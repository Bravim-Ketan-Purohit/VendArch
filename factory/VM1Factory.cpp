// File: factory/VM1Factory.cpp
// Purpose: Implements the concrete factory for VM_1 (float-based)
// This class instantiates DS1 and all strategy classes using DS1 as input.

#include "VM1Factory.h"
#include "../model/DS1.h"
#include "../strategy/CreateMsg1.h"
#include "../strategy/DisposeDrink1.h"
#include "../strategy/DisposeAdditives1.h"
#include "../strategy/SetPrice1.h"
#include "../strategy/ReturnCoins1.h"
#include "../strategy/StorePrice1.h"
#include "../strategy/CoinPayment.h"
#include "../strategy/CardPayment.h"
#include "../output/OP.h"

VM1Factory::VM1Factory()
{
    ds = new DS1(); // Float-compatible DataStore
}

DataStore *VM1Factory::createDataStore()
{
    return ds;
}

CreateMsg *VM1Factory::createCreateMsgStrategy()
{
    return new CreateMsg1();
}

DisposeDrink *VM1Factory::createDisposeDrinkStrategy()
{
    return new DisposeDrink1();
}

DisposeAdditives *VM1Factory::createDisposeAdditivesStrategy()
{
    return new DisposeAdditives1();
}

SetPrice *VM1Factory::createSetPriceStrategy()
{
    return new SetPrice1();
}

ReturnCoins *VM1Factory::createReturnCoinsStrategy()
{
    return new ReturnCoins1();
}

StorePrice *VM1Factory::createStorePriceStrategy()
{
    return new StorePrice1();
}

PaymentStrategy *VM1Factory::createCoinPaymentStrategy()
{
    return new CoinPayment();
}

PaymentStrategy *VM1Factory::createCardPaymentStrategy()
{
    return new CardPayment();
}

OP *VM1Factory::createOP()
{
    OP *op = new OP();
    op->setCreateMsg(createCreateMsgStrategy());
    op->setDisposeDrink(createDisposeDrinkStrategy());
    op->setDisposeAdditives(createDisposeAdditivesStrategy());
    op->setSetPrice(createSetPriceStrategy());
    op->setReturnCoins(createReturnCoinsStrategy());
    op->setStorePrice(createStorePriceStrategy());
    return op;
}
