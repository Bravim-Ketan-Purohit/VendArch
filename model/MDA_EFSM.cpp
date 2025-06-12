#include "MDA_EFSM.h"
#include "DataStore.h"
#include "../state/State.h"
#include "../state/Idle.h"
#include "../state/NoCups.h"
#include "../state/CoinsInserted.h"
#include "../output/OP.h"

MDA_EFSM::MDA_EFSM(DataStore *datastore)
{
    ds = datastore;

    idleState = new Idle(this);
    noCupsState = new NoCups(this);
    coinsInsertedState = new CoinsInserted(this);

    currentState = noCupsState;
    op = nullptr; // will be injected via setOP()
}

void MDA_EFSM::setOP(OP *outputProcessor)
{
    op = outputProcessor;
}

// Delegation to states
void MDA_EFSM::create() { currentState->create(); }
void MDA_EFSM::insert_cups(int n) { currentState->insert_cups(n); }
void MDA_EFSM::coin(float v) { currentState->coin(v); }
void MDA_EFSM::card(float x) { currentState->card(x); }
void MDA_EFSM::set_price(float p) { currentState->set_price(p); }
void MDA_EFSM::cancel() { currentState->cancel(); }
void MDA_EFSM::cappuccino() { currentState->cappuccino(); }
void MDA_EFSM::chocolate() { currentState->chocolate(); }
void MDA_EFSM::sugar() { currentState->sugar(); }

void MDA_EFSM::change_state(State *s)
{
    currentState = s;
}

State *MDA_EFSM::getIdleState() { return idleState; }
State *MDA_EFSM::getNoCupsState() { return noCupsState; }
State *MDA_EFSM::getCoinsInsertedState() { return coinsInsertedState; }

std::string MDA_EFSM::getCurrentStateName()
{
    if (currentState == idleState)
        return "Idle";
    if (currentState == noCupsState)
        return "NoCups";
    if (currentState == coinsInsertedState)
        return "CoinsInserted";
    return "Unknown";
}

MDA_EFSM::~MDA_EFSM()
{
    delete idleState;
    delete noCupsState;
    delete coinsInsertedState;
}
