#include "mpl_statepaused.h"

MPL_StatePaused::MPL_StatePaused(MPL_BASSDevice &device) :
    _device(&device)
{
}

MPL_AbstractState *MPL_StatePaused::play(const char *filePath)
{
    // M:
    // dopuszczasz to ze nie uda sie wykonac tej operacji?
    // Poza tym moglbys napisac:
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
        // moglbys tutaj zwrocic this
        return new MPL_StatePaused(*_device);
    }
}

MPL_AbstractState *MPL_StatePaused::pause()
{
    // M:
    // moglbys tutaj zwrocic this
    return new MPL_StatePaused(*_device);
}

MPL_AbstractState *MPL_StatePaused::stop()
{
    // M:
    // dopuszczasz to ze nie uda sie wykonac tej operacji?
    if(_device->stop())
    {
        return new MPL_StateIdle(*_device);
    }
    else
    {
		// M:
        return new MPL_StatePaused(*_device);
    }
}
