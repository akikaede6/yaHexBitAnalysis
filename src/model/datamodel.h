#ifndef DATAMODEL_H
#define DATAMODEL_H

#include <boost/algorithm/string.hpp>
#include <QObject>
#include <ranges>

using std::shared_ptr;
using std::ranges::views::iota;
using std::string;
using std::vector;

class DataModel : public QObject
{
    Q_OBJECT
public:
    explicit DataModel(QObject *parent = nullptr);

    void setInput(const std::string &newInput, int row, int column);

    int row() const;
    void setRow(int newRow);
    void addOneRow();

    int column() const;
    void setColumn(int newColumn);
    void addOneColumn();

private:
    string expressionOperate(const string &input);
    string hexToBin(const string &hex);
    string binToHex(const string &bin);
    string binToDec(const string &bin);

private:
    struct Digital
    {
        string m_input;
        string m_inputHex;
        string m_inputBin;
        string m_output;
        string m_outputBin;
        string m_selectedInput;
        string m_selectedOutput;
        string m_name;
    };
    vector<vector<shared_ptr<Digital>>> m_digitalVec;
    int m_row{0};
    int m_column{0};
};

#endif // DATAMODEL_H
