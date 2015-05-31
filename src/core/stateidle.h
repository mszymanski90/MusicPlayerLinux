#ifndef STATEIDLE_H
#define STATEIDLE_H

#include "iplayerstate.h"
#include "iplayer.h"

class StateIdle : public IPlayerState
{
public:
    StateIdle(IPlayer& player);
    IPlayerState* play(const char *filePath);
    IPlayerState* pause();
    IPlayerState* stop();
    IPlayerState* seek(int timeInSeconds);

private:
    IPlayer& player_;
};

#endif // STATEIDLE_H
