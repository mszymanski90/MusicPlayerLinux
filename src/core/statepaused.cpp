#include "stateidle.h"
#include "statepaused.h"
#include "stateplayback.h"

StatePaused::StatePaused(IPlayer &player) :
    player_(player)
{
}

IPlayerState *StatePaused::play(const char *filePath)
{
    // M:
    // dopuszczasz to ze nie uda sie wykonac tej operacji?
    // Poza tym moglbys napisac:
    /*
    if(_device->resume())
        return new StatePlayback(*_device);
    return this;
    */
    if(player_.resume())
    {
        return new StatePlayback(player_);
    }
    else
    {
        // M:
        // moglbys tutaj zwrocic this
        return new StatePaused(player_);
    }
}

IPlayerState *StatePaused::pause()
{
    // M:
    // moglbys tutaj zwrocic this
    return new StatePaused(player_);
}

IPlayerState *StatePaused::stop()
{
    // M:
    // dopuszczasz to ze nie uda sie wykonac tej operacji?
    if(player_.stop())
    {
        return new StateIdle(player_);
    }
    else
    {
		// M:
        return new StatePaused(player_);
    }
}

IPlayerState *StatePaused::seek(int timeInSeconds)
{
    player_.seek(timeInSeconds);
    return new StatePaused(player_);
}
