#ifndef MPLCORE_H
#define MPLCORE_H

#include <string>
#include "bass.h"
#include "loggerdevice.h"

// fix that later
#define MAX_PATH 100

class MPLCore
{
private:
    HSTREAM _currentHStream;
    LoggerDevice* _logger;

public:
    MPLCore();
    void init(LoggerDevice* logger);
    void loadFile(std::string filePath);
    void play();
    void stop();
    void pause();
    void setVolume();
};

#endif // MPLCORE_H
