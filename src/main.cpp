#include "mainwindow.h"
//#include "model/datamodel.h"

#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //    datamodel ab;
    //    ab.setHexInputData("FFFF");
    //    std::cout << ab.hexInputData().toStdString() << std::endl;
    //    std::cout << ab.binInputData().toStdString() << std::endl;

    //    ab.setBinOutputData("1110100010");
    //    std::cout << ab.binOutputData().toStdString() << std::endl;
    //    std::cout << ab.hexOutputData().toStdString() << std::endl;
    return a.exec();
}
