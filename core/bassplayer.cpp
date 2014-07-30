#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "bassplayer.h"

BASSPlayer::BASSPlayer(IPlayerObserver& observer, LoggerDevice &logger) :
    IPlayer(observer),
    logger_(logger),
    currentHStream_(0),
    playbackStopped_(true)
{
    fileprocs.close = &BASSPlayer::closeFileProc;
    fileprocs.length = &BASSPlayer::fileLenProc;
    fileprocs.read = &BASSPlayer::fileReadProc;
    fileprocs.seek = &BASSPlayer::fileSeekProc;
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

bool BASSPlayer::seek(int timeInSeconds)
{
    return BASS_ChannelSetPosition(currentHStream_,
                                   BASS_ChannelSeconds2Bytes(currentHStream_, timeInSeconds),
                                   BASS_POS_BYTE);
}

void BASSPlayer::notify()
{
    observer_.update(playbackStopped_, getPositionInSeconds(), getDurationInSeconds());
}

void BASSPlayer::openStream()
{
    logger_.log(std::string("Core open stream"));
    file = fopen(file_, "rb"); // open the file
    currentHStream_ = BASS_StreamCreateFileUser(STREAMFILE_NOBUFFER,
                                                0,
                                                &fileprocs,
                                                reinterpret_cast<void*>(this));

    BASS_ChannelSetSync(currentHStream_, BASS_SYNC_END | BASS_SYNC_ONETIME, 0, &BASSPlayer::endReachedProc, reinterpret_cast<void*>(this));
}

double BASSPlayer::getPositionInSeconds()
{
    return BASS_ChannelBytes2Seconds(currentHStream_, BASS_ChannelGetPosition(currentHStream_, BASS_POS_BYTE));
}

double BASSPlayer::getDurationInSeconds()
{
    return BASS_ChannelBytes2Seconds(currentHStream_, BASS_ChannelGetLength(currentHStream_, BASS_POS_BYTE));
}

void CALLBACK BASSPlayer::closeFileProc(void *user)
{
    fclose(reinterpret_cast<BASSPlayer*>(user)->file); // close the file
}

QWORD CALLBACK BASSPlayer::fileLenProc(void *user)
{
    struct stat s;
    fstat(fileno(reinterpret_cast<BASSPlayer*>(user)->file), &s);
    return s.st_size;
}

DWORD CALLBACK BASSPlayer::fileReadProc(void *buffer, DWORD length, void *user)
{
    reinterpret_cast<BASSPlayer*>(user)->playbackStopped_ = false;
    reinterpret_cast<BASSPlayer*>(user)->notify();
    return fread(buffer, 1, length, reinterpret_cast<BASSPlayer*>(user)->file);
}

BOOL CALLBACK BASSPlayer::fileSeekProc(QWORD offset, void *user)
{
    reinterpret_cast<BASSPlayer*>(user)->notify();
    return !fseek(reinterpret_cast<BASSPlayer*>(user)->file, offset, SEEK_SET);
}

void BASSPlayer::endReachedProc(HSYNC handle, DWORD channel, DWORD data, void *user)
{
    reinterpret_cast<BASSPlayer*>(user)->playbackStopped_ = true;
    reinterpret_cast<BASSPlayer*>(user)->notify();
}
