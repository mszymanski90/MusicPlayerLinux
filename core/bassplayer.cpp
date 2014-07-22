#include "bassplayer.h"

BASSPlayer::BASSPlayer()
{
    _currentHStream = 0;
}

BASSPlayer::~BASSPlayer()
{
    BASS_Free();
}

void BASSPlayer::init()
{
    BASS_Init(-1,44100,0,0,NULL);
}

bool BASSPlayer::play(const char *filePath)
{
    strcpy(_file, filePath);
    openStream();
    return BASS_ChannelPlay(_currentHStream, TRUE);
}

bool BASSPlayer::resume()
{
    return BASS_ChannelPlay(_currentHStream, FALSE);
}

bool BASSPlayer::pause()
{
    return BASS_ChannelStop(_currentHStream);
}

bool BASSPlayer::stop()
{
    if(BASS_ChannelStop(_currentHStream) && BASS_StreamFree(_currentHStream))
    {
        return true;
    }
    else return false;
}

bool BASSPlayer::setVolume(float volume)
{
    return BASS_SetVolume(volume);
}

void BASSPlayer::openStream()
{
    _currentHStream = BASS_StreamCreateFile(FALSE, _file, 0, 0, 0);
}


