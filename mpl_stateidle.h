#ifndef MPL_STATEIDLE_H
#define MPL_STATEIDLE_H

#include "mpl_abstractstate.h"
#include "mpl_bassdevice.h"
// M:
// Po co include
#include "mpl_stateplayback.h"

class MPL_StateIdle : public MPL_AbstractState
{
public:
    MPL_StateIdle(MPL_BASSDevice& device);
    MPL_AbstractState* play(const char *filePath);
    MPL_AbstractState* pause();
    MPL_AbstractState* stop();

private:
    MPL_BASSDevice* _device;
};

#endif // MPL_STATEIDLE_H
