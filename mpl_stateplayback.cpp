#include "mpl_stateplayback.h"

MPL_StatePlayback::MPL_StatePlayback(MPL_BASSDevice &device) :
    _device(&device)
{
}

MPL_AbstractState *MPL_StatePlayback::play(const char *filePath)
{
    // M:
    // móg³byœ tutaj zwróciæ this
    return new MPL_StatePlayback(*_device);
}

MPL_AbstractState *MPL_StatePlayback::pause()
{
    if(_device->pause())
    {
        return new MPL_StatePaused(*_device);
    }
    else
    {
        // M:
        // móg³byœ tutaj zwróciæ this
        return new MPL_StatePlayback(*_device);
    }
}

MPL_AbstractState *MPL_StatePlayback::stop()
{
    if(_device->stop())
    {
        return new MPL_StateIdle(*_device);
    }
    else
    {
        // M:
        // móg³byœ tutaj zwróciæ this
        return new MPL_StatePlayback(*_device);
    }
}
