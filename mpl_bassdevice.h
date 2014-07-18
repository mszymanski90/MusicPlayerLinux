#ifndef MPL_BASSDEVICE_H
#define MPL_BASSDEVICE_H

#include "bass.h"

#ifndef _WIN32
    // fix this value later
    #define MAX_PATH 260
#endif

class MPL_BASSDevice
{
public:
    MPL_BASSDevice();
    ~MPL_BASSDevice();
    void init();
    bool play(const char *filePath);
    bool resume();
    bool pause();
    bool stop();
    bool setVolume(int setValue);

private:
    HSTREAM _currentHStream;
    char _file[MAX_PATH];

    void openStream();
};

#endif // MPL_BASSDEVICE_H
