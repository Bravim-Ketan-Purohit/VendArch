#include "CoinsInserted.h"
#include "../model/MDA_EFSM.h"
#include "../model/DataStore.h"
#include "../model/DS1.h"
#include "../output/OP.h"
#include <iostream>
using namespace std;

CoinsInserted::CoinsInserted(MDA_EFSM *m) : State(m) {}

void CoinsInserted::cappuccino()
{
    if (efsm->ds->get_k() > 0)
    {
        cout << "[CoinsInserted] Dispensing cappuccino";
        if (efsm->ds->get_additive(0))
            cout << " with sugar";
        cout << "." << endl;

        efsm->op->dispose_drink();
        if (efsm->ds->get_additive(0))
            efsm->op->dispose_additives();

        efsm->ds->set_k(efsm->ds->get_k() - 1);
        float overpaid = efsm->ds->get_cf() - efsm->ds->get_price();
        if (overpaid > 0)
        {
            efsm->ds->set_cf(overpaid);
            efsm->op->return_coins();
        }
        efsm->ds->set_cf(0); // ✅ always reset after refund

        efsm->ds->set_additive(0, 0);

        if (efsm->ds->get_k() == 0)
        {
            cout << "[CoinsInserted] Cups finished. Switching to NoCups state." << endl;
            efsm->change_state(efsm->getNoCupsState());
        }
        else
        {
            efsm->change_state(efsm->getIdleState());
        }
    }
    else
    {
        cout << "[CoinsInserted] No cups left!" << endl;
    }
}

void CoinsInserted::chocolate()
{
    if (efsm->ds->get_k() > 0)
    {
        cout << "[CoinsInserted] Dispensing chocolate";
        if (efsm->ds->get_additive(0))
            cout << " with sugar";
        cout << "." << endl;

        efsm->op->dispose_drink();
        if (efsm->ds->get_additive(0))
            efsm->op->dispose_additives();

        efsm->ds->set_k(efsm->ds->get_k() - 1);

        float overpaid = efsm->ds->get_cf() - efsm->ds->get_price();
        if (overpaid > 0)
        {
            efsm->ds->set_cf(overpaid);
            efsm->op->return_coins();
        }
        efsm->ds->set_cf(0); // ✅ always reset after refund

        efsm->ds->set_additive(0, 0);

        if (efsm->ds->get_k() == 0)
        {
            cout << "[CoinsInserted] Cups finished. Switching to NoCups state." << endl;
            efsm->change_state(efsm->getNoCupsState());
        }
        else
        {
            efsm->change_state(efsm->getIdleState());
        }
    }
    else
    {
        cout << "[CoinsInserted] No cups left!" << endl;
    }
}

void CoinsInserted::sugar()
{
    efsm->ds->set_additive(0, 1);
    cout << "[CoinsInserted] Sugar added." << endl;
}

void CoinsInserted::cancel()
{
    efsm->op->return_coins();
    efsm->ds->set_cf(0);
    efsm->ds->set_additive(0, 0);
    efsm->change_state(efsm->getIdleState());
}
