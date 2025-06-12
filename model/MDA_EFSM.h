#ifndef MDA_EFSM_H
#define MDA_EFSM_H

#include <string>

// Forward declarations
class State;
class Idle;
class NoCups;
class CoinsInserted;
class DataStore;
class OP;

class MDA_EFSM
{
private:
    State *currentState;
    Idle *idleState;
    NoCups *noCupsState;
    CoinsInserted *coinsInsertedState;

public:
    OP *op;
    DataStore *ds;

    MDA_EFSM(DataStore *datastore);

    void setOP(OP *outputProcessor); // ✅ Inject OP

    void change_state(State *s);

    // API methods
    void create();
    void insert_cups(int n);
    void coin(float v);
    void card(float x);
    void set_price(float p);
    void cancel();
    void cappuccino();
    void chocolate();
    void sugar();

    // Getters
    State *getIdleState();
    State *getNoCupsState();
    State *getCoinsInsertedState();

    std::string getCurrentStateName();

    ~MDA_EFSM();
};

#endif
