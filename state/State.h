#ifndef STATE_H
#define STATE_H

class MDA_EFSM;

class State
{
protected:
    MDA_EFSM *efsm;

public:
    State(MDA_EFSM *m);

    virtual void create();
    virtual void insert_cups(int n);
    virtual void coin(float v);
    virtual void card(float x);
    virtual void set_price(float p);
    virtual void cancel();
    virtual void cappuccino();
    virtual void chocolate();
    virtual void sugar();

    virtual ~State();
};

#endif
