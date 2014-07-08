#ifndef LOGGERDEVICE_H
#define LOGGERDEVICE_H

#include <QObject>

class LoggerDevice : public QObject
{
    Q_OBJECT
public:
    explicit LoggerDevice(QObject *parent = 0);

signals:

public slots:

};

#endif // LOGGERDEVICE_H
