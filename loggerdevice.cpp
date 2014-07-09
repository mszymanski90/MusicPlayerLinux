#include "loggerdevice.h"

LoggerDevice::LoggerDevice(QObject *parent) :
    QObject(parent)
{
    std::cout << "Music Player Linux 0.01 log:" << std::endl;
}

void LoggerDevice::log(std::string message)
{
    std::cout << message << std::endl;
}
