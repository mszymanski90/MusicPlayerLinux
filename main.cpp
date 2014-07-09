#include "mainapplication.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainApplication mainApp;
    mainApp.init();

    return a.exec();
}
