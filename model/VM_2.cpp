// File: model/VM_2.cpp
// Purpose: Implements all methods of VM_2 including strategy interactions

#include "VM_2.h"
#include "../output/OP.h"
#include "../strategy/PaymentStrategy.h"

VM_2::VM_2(AbstractFactory *factory)
{
    af = factory;
    ds = af->createDataStore(); // This will be DS2
    mda = new MDA_EFSM(ds);

    OP *op = af->createOP();
    mda->setOP(op);
}

void VM_2::CREATE(int p)
{
    ds->set_temp_p(p);
    mda->create();
}

void VM_2::COIN(int v)
{
    PaymentStrategy *ps = af->createCoinPaymentStrategy();
    ps->pay(ds, v);
    delete ps;
    mda->coin(v);
}

void VM_2::CARD(int x)
{
    PaymentStrategy *ps = af->createCardPaymentStrategy();
    ps->pay(ds, x);
    delete ps;
    mda->card(x);
}

void VM_2::SUGAR()
{
    mda->additive(0); // sugar = 0
}

void VM_2::CREAM()
{
    mda->additive(1); // cream = 1
}

void VM_2::COFFEE()
{
    mda->dispose_drink(0); // coffee = 0
}

void VM_2::InsertCups(int n)
{
    mda->insert_cups(n);
}

void VM_2::SetPrice(int p)
{
    ds->set_temp_p(p);
    mda->set_price();
}

void VM_2::CANCEL()
{
    mda->cancel();
}

std::string VM_2::getStateName()
{
    return mda->getCurrentStateName();
}

VM_2::~VM_2()
{
    delete mda;
    delete ds;
}
