#include "mpl_statepaused.h"

MPL_StatePaused::MPL_StatePaused(MPL_BASSDevice &device) :
    _device(&device)
{
}

MPL_AbstractState *MPL_StatePaused::play(const char *filePath)
{
    if(_device->resume())
    {
        return new MPL_StatePlayback(*_device);
    }
    else
    {
        return new MPL_StatePaused(*_device);
    }
}

MPL_AbstractState *MPL_StatePaused::pause()
{
    return new MPL_StatePaused(*_device);
}

MPL_AbstractState *MPL_StatePaused::stop()
{
    if(_device->stop())
    {
        return new MPL_StateIdle(*_device);
    }
    else
    {
        return new MPL_StatePaused(*_device);
    }
}
