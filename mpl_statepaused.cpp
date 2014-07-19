#include "mpl_statepaused.h"

MPL_StatePaused::MPL_StatePaused(MPL_BASSDevice &device) :
    _device(&device)
{
}

MPL_AbstractState *MPL_StatePaused::play(const char *filePath)
{
    // M:
    // dopuszczasz to �e nie uda si� wykona� tej operacji?
    // Poza tym m�g�by� napisa�:
    /*
    if(_device->resume())
        return new MPL_StatePlayback(*_device);
    return this;
    */
    if(_device->resume())
    {
        return new MPL_StatePlayback(*_device);
    }
    else
    {
        // M:
        // m�g�by� tutaj zwr�ci� this
        return new MPL_StatePaused(*_device);
    }
}

MPL_AbstractState *MPL_StatePaused::pause()
{
    // M:
    // m�g�by� tutaj zwr�ci� this
    return new MPL_StatePaused(*_device);
}

MPL_AbstractState *MPL_StatePaused::stop()
{
    // M:
    // dopuszczasz to �e nie uda si� wykona� tej operacji?
    if(_device->stop())
    {
        return new MPL_StateIdle(*_device);
    }
    else
    {
        // M:
        // m�g�by� tutaj zwr�ci� this
        return new MPL_StatePaused(*_device);
    }
}
