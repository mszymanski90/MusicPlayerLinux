#ifndef STATEPAUSED_H
#define STATEPAUSED_H

#include "iplayerstate.h"
#include "iplayer.h"

class StatePaused : public IPlayerState
{
public:
    StatePaused(IPlayer& player);
    IPlayerState* play(const char *filePath);
    IPlayerState* pause();
    IPlayerState* stop();

private:
    IPlayer& player_;
};

#endif // STATEPAUSED_H
