#include "stateplayback.h"
#include "stateidle.h"


StateIdle::StateIdle(IPlayer &player) :
    player_(player)
{
}

IPlayerState *StateIdle::play(const char *filePath)
{
    if(player_.play(filePath))
    {
        return new StatePlayback(player_);
    }
    else
    {
        return new StateIdle(player_);
    }
}

IPlayerState *StateIdle::pause()
{
    return new StateIdle(player_);
}

IPlayerState *StateIdle::stop()
{
    return new StateIdle(player_);
}

IPlayerState *StateIdle::seek(int timeInSeconds)
{
    return new StateIdle(player_);
}
