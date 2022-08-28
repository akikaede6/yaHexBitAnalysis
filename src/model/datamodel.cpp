#include "datamodel.h"

#include <ranges>

using std::ranges::views::iota;

DataModel::DataModel(QObject *parent)
    : QObject{parent}
{
    m_digitalVec[m_row][m_column] = shared_ptr<Digital>(new Digital);
}

void DataModel::setInput(const std::string &newInput, int row, int column)
{
    if (m_digitalVec[row][column] != nullptr) {
        m_digitalVec[row][column]->m_input = newInput;
    } else {
        shared_ptr<Digital> dig(new Digital);
        dig->m_input = newInput;
        m_digitalVec[row][column] = dig;
    }
}

int DataModel::row() const
{
    return m_row;
}

void DataModel::setRow(int newRow)
{
    if (newRow > m_row) {
        for (int i : iota(m_row, newRow)) {
            for (int j : iota(0, m_column)) {
                m_digitalVec[i][j] = shared_ptr<Digital>(new Digital);
            }
        }
    }
    m_row = newRow;
}

void DataModel::addOneRow()
{
    m_row++;
    for (int i : iota(0, m_column)) {
        m_digitalVec[m_row][i] = shared_ptr<Digital>(new Digital);
    }
}

int DataModel::column() const
{
    return m_column;
}

void DataModel::setColumn(int newColumn)
{
    m_column = newColumn;
}

void DataModel::addOneColumn()
{
    m_column++;
    for (int i : iota(0, m_row)) {
        m_digitalVec[i][m_column] = shared_ptr<Digital>(new Digital);
    }
}

std::string DataModel::expressionOperate(const std::string &input) {}

std::string DataModel::hexToBin(const std::string &hex) {}

std::string DataModel::binToHex(const std::string &bin) {}

std::string DataModel::binToDec(const std::string &bin) {}
