#ifndef MAINAPPLICATION_H
#define MAINAPPLICATION_H

#include <string>
#include <QObject>
#include <QFileDialog>
#include "mainwindow.h"
#include "mplcore.h"
#include "loggerdevice.h"

class MainApplication : public QObject
{
    Q_OBJECT
public:
    explicit MainApplication(QObject *parent = 0);
    void init();

private:
    MainWindow window;
    MPLCore core;
    LoggerDevice logger;

    std::string getPathFromFileDialog();

signals:

public slots:
    void loadFile();
    void play();
};

#endif // MAINAPPLICATION_H
