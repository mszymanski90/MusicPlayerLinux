#include "stateidle.h"
#include "statepaused.h"
#include "stateplayback.h"

StatePlayback::StatePlayback(IPlayer &player) :
    player_(player)
{
}

IPlayerState *StatePlayback::play(const char *filePath)
{
    // M:
    // this
    return new StatePlayback(player_);
}

IPlayerState *StatePlayback::pause()
{
    if(player_.pause())
    {
        return new StatePaused(player_);
    }
    else
    {
        // M:
        // this
        return new StatePlayback(player_);
    }
}

IPlayerState *StatePlayback::stop()
{
    if(player_.stop())
    {
        return new StateIdle(player_);
    }
    else
    {
        // M:
        // this
        return new StatePlayback(player_);
    }
}
