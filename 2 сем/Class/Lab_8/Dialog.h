#pragma once
#include "Event.h"
#include "Vector.h"


class Dialog : public Vector
{
protected:
    int EndState;

public:
    Dialog(void);
    virtual ~Dialog(void);
    virtual void GetEvent(TEvent&);
    virtual int Execute();
    virtual void HandleEvent(TEvent&);
    virtual void ClearEvent(TEvent&);
    int Valid();
    void EndExec();
};