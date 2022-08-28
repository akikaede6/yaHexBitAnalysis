#ifndef DATATEST_H
#define DATATEST_H

#include <QObject>

class DataTest : public QObject
{
    Q_OBJECT
public:
    explicit DataTest(QObject *parent = nullptr);

signals:

    //private slots:
    //    void initTestCase();

    //private:
    //    void hexToBin_test();
};

#endif // DATATEST_H
