#include "mpl_stateidle.h"

MPL_StateIdle::MPL_StateIdle(MPL_BASSDevice &device) :
    _device(&device)
{
}

MPL_AbstractState *MPL_StateIdle::play(const char *filePath)
{
    if(_device->play(filePath))
    {
        return new MPL_StatePlayback(*_device);
    }
    else
    {
        return new MPL_StateIdle(*_device);
    }
}

MPL_AbstractState *MPL_StateIdle::pause()
{
    return new MPL_StateIdle(*_device);
}

MPL_AbstractState *MPL_StateIdle::stop()
{
    return new MPL_StateIdle(*_device);
}
