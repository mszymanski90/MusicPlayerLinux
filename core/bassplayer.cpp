#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "bassplayer.h"

BASSPlayer::BASSPlayer(LoggerDevice &logger, std::function<void(double)> coreUpdatePositionProc) :
    currentHStream_(0),
    logger_(logger),
    coreUpdatePositionProc_(coreUpdatePositionProc)
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

double BASSPlayer::getDuration()
{
    return BASS_ChannelBytes2Seconds(currentHStream_,
                                     BASS_ChannelGetLength(currentHStream_, BASS_POS_BYTE));
}

void BASSPlayer::openStream()
{
    logger_.log(std::string("Core open stream"));
    file = fopen(file_, "rb"); // open the file
    currentHStream_ = BASS_StreamCreateFileUser(STREAMFILE_NOBUFFER,
                                                0,
                                                &fileprocs,
                                                reinterpret_cast<void*>(this));
}

void BASSPlayer::updatePosition()
{
    coreUpdatePositionProc_(BASS_ChannelBytes2Seconds(currentHStream_, BASS_ChannelGetPosition(currentHStream_, BASS_POS_BYTE)));
}

void CALLBACK BASSPlayer::closeFileProc(void *user)
{
    fclose(reinterpret_cast<BASSPlayer*>(user)->file); // close the file
}

QWORD CALLBACK BASSPlayer::fileLenProc(void *user)
{
    struct stat s;
    fstat(fileno(reinterpret_cast<BASSPlayer*>(user)->file), &s);
    return s.st_size; // return the file length
}

DWORD CALLBACK BASSPlayer::fileReadProc(void *buffer, DWORD length, void *user)
{
    reinterpret_cast<BASSPlayer*>(user)->updatePosition();
    return fread(buffer, 1, length, reinterpret_cast<BASSPlayer*>(user)->file);
}

BOOL CALLBACK BASSPlayer::fileSeekProc(QWORD offset, void *user)
{
    //reinterpret_cast<BASSPlayer*>(user)->updatePosition();
    return !fseek(reinterpret_cast<BASSPlayer*>(user)->file, offset, SEEK_SET);
}
