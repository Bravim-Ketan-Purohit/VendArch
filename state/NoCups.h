#ifndef NOCUPS_H
#define NOCUPS_H

#include "State.h"

class NoCups : public State
{
public:
    NoCups(MDA_EFSM *m);

    void create() override;
    void insert_cups(int n) override;
};

#endif
