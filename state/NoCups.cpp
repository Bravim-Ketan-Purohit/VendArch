#include "NoCups.h"
#include "../model/MDA_EFSM.h"
#include "../model/DataStore.h"
#include "../output/OP.h"
#include <iostream>
using namespace std;

NoCups::NoCups(MDA_EFSM *m) : State(m) {}

void NoCups::create()
{
    float price = efsm->ds->get_temp_p();
    efsm->op->store_price();
    efsm->op->create();
    efsm->change_state(efsm->getNoCupsState());
}

void NoCups::insert_cups(int n)
{
    if (n > 0)
    {
        efsm->ds->set_k(efsm->ds->get_k() + n);
        cout << "[NoCups] Inserted " << n << " cups. Transitioning to Idle state." << endl;
        efsm->change_state(efsm->getIdleState());
    }
    else
    {
        cout << "[NoCups] Invalid cup amount." << endl;
    }
}
