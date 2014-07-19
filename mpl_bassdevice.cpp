#include "mpl_bassdevice.h"

MPL_BASSDevice::MPL_BASSDevice()
{
    _currentHStream = 0;
}

MPL_BASSDevice::~MPL_BASSDevice()
{
    BASS_Free();
}

void MPL_BASSDevice::init()
{
    BASS_Init(-1,44100,0,0,NULL);
}

bool MPL_BASSDevice::play(const char *filePath)
{
    strcpy(_file, filePath);
    openStream();
    BASS_ChannelPlay(_currentHStream, TRUE);
    // M:
    // gdzie return? Jest w ogóle potrzebny?
}

bool MPL_BASSDevice::resume()
{
    // M:
    // mog³oby byæ po prostu
    // return BASS_ChannelPlay(_currentHStream, FALSE);
    if(BASS_ChannelPlay(_currentHStream, FALSE)) return true;
    else return false;
}

bool MPL_BASSDevice::pause()
{
    // M:
    // j.w.
    if(BASS_ChannelStop(_currentHStream)) return true;
    else return false;
}

bool MPL_BASSDevice::stop()
{
    // M:
    // j.w.
    if(BASS_ChannelStop(_currentHStream) && BASS_StreamFree(_currentHStream))
    {
        return true;
    }
    else return false;
}

bool MPL_BASSDevice::setVolume(int setValue)
{
    return false;
}

void MPL_BASSDevice::openStream()
{
    _currentHStream = BASS_StreamCreateFile(FALSE, _file, 0, 0, 0);
}


