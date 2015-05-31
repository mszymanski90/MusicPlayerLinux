#ifndef STATEPLAYBACK_H
#define STATEPLAYBACK_H

#include "iplayerstate.h"
#include "iplayer.h"

class StatePlayback : public IPlayerState
{
public:
    StatePlayback(IPlayer& player);
    IPlayerState* play(const char *filePath);
    IPlayerState* pause();
    IPlayerState* stop();
    IPlayerState* seek(int timeInSeconds);

private:
    IPlayer& player_;
};

#endif // STATEPLAYBACK_H
