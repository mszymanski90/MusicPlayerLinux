#include <string.h>
#include "bassplayer.h"

BASSPlayer::BASSPlayer(LoggerDevice &logger) :
    currentHStream_(0),
    logger_(logger)
{
}

BASSPlayer::~BASSPlayer()
{
    if(!BASS_Free()) logger_.log(std::string("Core free error"));
}

bool BASSPlayer::init()
{
    logger_.log(std::string("Core init"));
    return BASS_Init(-1, 44100, 0, 0, nullptr);
}

bool BASSPlayer::play(const char *filePath)
{
    logger_.log(std::string("Core play"));
    strcpy(file_, filePath);
    openStream();
    return BASS_ChannelPlay(currentHStream_, TRUE);
}

bool BASSPlayer::resume()
{
    logger_.log(std::string("Core resume"));
    return BASS_ChannelPlay(currentHStream_, FALSE);
}

bool BASSPlayer::pause()
{
    logger_.log(std::string("Core pause"));
    return BASS_ChannelStop(currentHStream_);
}

bool BASSPlayer::stop()
{
    logger_.log(std::string("Core stop"));
    if(BASS_ChannelStop(currentHStream_) && BASS_StreamFree(currentHStream_))
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
    logger_.log(std::string("Core open stream"));
    currentHStream_ = BASS_StreamCreateFile(FALSE, file_, 0, 0, 0);
}


