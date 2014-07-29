#ifndef IPLAYEROBSERVER_H
#define IPLAYEROBSERVER_H

class IPlayerObserver;
class IPlayerSubject;

class IPlayerObserver
{
public:
    virtual void update(bool playbackStopped, double position, double duration) = 0;
};

class IPlayerSubject
{
public:
    IPlayerSubject(IPlayerObserver& observer);
    virtual void notify() = 0;
protected:
    IPlayerObserver& observer_;
};

#endif // IPLAYEROBSERVER_H
