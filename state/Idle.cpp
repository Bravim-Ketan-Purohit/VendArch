#include "Idle.h"
#include "../model/MDA_EFSM.h"
#include "../model/DataStore.h"
#include "../output/OP.h"
#include <iostream>
using namespace std;

Idle::Idle(MDA_EFSM *m) : State(m) {}

void Idle::insert_cups(int n)
{
    if (n > 0)
    {
        efsm->ds->set_k(efsm->ds->get_k() + n);
        cout << "[Idle] Inserted " << n << " cups. Total: " << efsm->ds->get_k() << endl;
    }
    else
    {
        cout << "[Idle] Invalid number of cups." << endl;
    }
}

void Idle::coin(float v)
{
    float new_cf = efsm->ds->get_cf();
    efsm->ds->set_cf(new_cf);

    efsm->op->set_price(efsm->ds->get_price());
    cout << "[Idle] Coin inserted. Current funds: " << efsm->ds->get_cf() << endl;

    if (efsm->ds->get_cf() >= efsm->ds->get_price())
    {
        efsm->change_state(efsm->getCoinsInsertedState());
    }
}

void Idle::card(float x)
{
    efsm->ds->set_cf(x);
    efsm->op->set_price(efsm->ds->get_price());

    if (efsm->ds->get_cf() >= efsm->ds->get_price())
    {
        efsm->ds->set_cf(0);
        cout << "[Idle] Card accepted. Moving to CoinsInserted state." << endl;
        efsm->change_state(efsm->getCoinsInsertedState());
    }
    else
    {
        cout << "[Idle] Card value too low." << endl;
    }
}
