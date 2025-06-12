#ifndef COINSINSERTED_H
#define COINSINSERTED_H

#include "State.h"

class CoinsInserted : public State
{
public:
    CoinsInserted(MDA_EFSM *m);

    void cappuccino() override;
    void chocolate() override;
    void sugar() override;
    void cancel() override;
};

#endif
