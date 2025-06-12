#ifndef IDLE_H
#define IDLE_H

#include "State.h"

class Idle : public State
{
public:
    Idle(MDA_EFSM *m);

    void insert_cups(int n) override;
    void coin(float v) override;
    void card(float x) override;
};

#endif
