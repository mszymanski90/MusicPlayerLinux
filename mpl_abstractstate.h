#ifndef MPL_ABSTRACTSTATE_H
#define MPL_ABSTRACTSTATE_H

class MPL_AbstractState
{
public:
    virtual MPL_AbstractState* play(const char *filePath) = 0;
    virtual MPL_AbstractState* pause() = 0;
    virtual MPL_AbstractState* stop() = 0;
};

#endif // MPL_ABSTRACTSTATE_H
