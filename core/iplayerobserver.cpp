#include "iplayerobserver.h"

IPlayerSubject::IPlayerSubject(IPlayerObserver &observer) :
    observer_(observer)
{
}
