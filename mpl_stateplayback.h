#ifndef MPL_STATEPLAYBACK_H
#define MPL_STATEPLAYBACK_H

#include "mpl_abstractstate.h"
#include "mpl_bassdevice.h"
#include "mpl_stateidle.h"
#include "mpl_statepaused.h"

class MPL_StatePlayback : public MPL_AbstractState
{
public:
    MPL_StatePlayback(MPL_BASSDevice& device);
    MPL_AbstractState* play(const char *filePath);
    MPL_AbstractState* pause();
    MPL_AbstractState* stop();

private:
    MPL_BASSDevice* _device;
};

#endif // MPL_STATEPLAYBACK_H
