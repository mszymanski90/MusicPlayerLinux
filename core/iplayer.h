#ifndef IPLAYER_H
#define IPLAYER_H

class IPlayer
{
public:
    virtual ~IPlayer();
    virtual bool init() = 0;
    // M:
    // Czemu nie std::string albo QString?
    virtual bool play(const char *filePath) = 0;
    virtual bool resume() = 0;
    virtual bool pause() = 0;
    virtual bool stop() = 0;
    virtual bool setVolume(float volume) = 0;
    virtual bool seek(int timeInSeconds) = 0;
    //virtual int getPositionInSeconds() = 0;
    //virtual int getDuration() = 0;
};

#endif // IPLAYER_H
