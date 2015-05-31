#include "iplayer.h"

IPlayer::IPlayer(IPlayerObserver &observer) :
    IPlayerSubject(observer)
{
}

IPlayer::~IPlayer()
{
}
