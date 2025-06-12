// File: model/VM_1.cpp
// Purpose: Implements VM_1 logic and delegates all DataStore operations
// to strategy classes. Coordinates with the MDA_EFSM for state transitions
// and OP for output behaviors.

#include "VM_1.h"
#include "MDA_EFSM.h"
#include "DataStore.h"
#include "DS1.h"
#include "../output/OP.h"
#include "../factory/AbstractFactory.h"
#include "../strategy/PaymentStrategy.h"

#include <iostream>
using namespace std;

VM_1::VM_1(AbstractFactory *factory)
{
    // Create shared DataStore (DS1)
    ds = factory->createDataStore();

    // Create and initialize state machine with DataStore
    efsm = new MDA_EFSM(ds);

    // Create payment strategies
    coinPayment = factory->createCoinPaymentStrategy();
    cardPayment = factory->createCardPaymentStrategy();

    // Inject output processor
    OP *op = factory->createOP();
    efsm->setOP(op);
}

void VM_1::create(float price)
{
    // Store temp price in DS via strategy logic
    ds->set_temp_p(price);
    efsm->create();
}

void VM_1::insert_cups(int n)
{
    efsm->insert_cups(n);
}

void VM_1::coin(float v)
{
    // Add amount to cf using strategy logic
    coinPayment->pay(ds, v);
    efsm->coin(v);
}

void VM_1::card(float x)
{
    // Card strategy performs validation + update
    cardPayment->pay(ds, x);
    efsm->card(x);
}

void VM_1::set_price(float p)
{
    // Update temp price
    ds->set_temp_p(p);
    efsm->set_price(p);
}

void VM_1::sugar()
{
    efsm->sugar();
}

void VM_1::cappuccino()
{
    efsm->cappuccino();
}

void VM_1::chocolate()
{
    efsm->chocolate();
}

void VM_1::cancel()
{
    efsm->cancel();
}

std::string VM_1::getStateName()
{
    return efsm->getCurrentStateName();
}

VM_1::~VM_1()
{
    delete efsm;
    delete ds;
    delete coinPayment;
    delete cardPayment;
}
