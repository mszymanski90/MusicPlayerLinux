#ifndef LOGGERDEVICE_H
#define LOGGERDEVICE_H

#include <iostream>
#include <string>
#include <QObject>

class LoggerDevice : public QObject
{
    Q_OBJECT
public:
    explicit LoggerDevice(QObject *parent = 0);

signals:

public slots:
    void log(std::string message);

};

#endif // LOGGERDEVICE_H
