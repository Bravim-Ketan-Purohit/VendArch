#include "VM2Factory.h"
#include "../output/OP.h"
#include "../model/DS2.h"

// Strategy includes for VM2
#include "../strategy/CreateMsg1.h"
#include "../strategy/DisposeDrink2.h"
#include "../strategy/DisposeAdditives2.h"
#include "../strategy/SetPrice2.h"
#include "../strategy/ReturnCoins2.h"
#include "../strategy/StorePrice2.h"
#include "../strategy/CoinPayment.h"
#include "../strategy/CardPayment.h"

VM2Factory::VM2Factory()
{
    ds = new DS2(); // ✅ int-based DataStore
}

DataStore *VM2Factory::createDataStore()
{
    return ds;
}

PaymentStrategy *VM2Factory::createCoinPaymentStrategy()
{
    return new CoinPayment();
}

PaymentStrategy *VM2Factory::createCardPaymentStrategy()
{
    return new CardPayment();
}

CreateMsg *VM2Factory::createCreateMsg()
{
    return new CreateMsg1(); // Reused
}

DisposeDrink *VM2Factory::createDisposeDrink()
{
    return new DisposeDrink2();
}

DisposeAdditives *VM2Factory::createDisposeAdditives()
{
    return new DisposeAdditives2(ds);
}

SetPrice *VM2Factory::createSetPrice()
{
    return new SetPrice2();
}

ReturnCoins *VM2Factory::createReturnCoins()
{
    return new ReturnCoins2(ds);
}

StorePrice *VM2Factory::createStorePrice()
{
    return new StorePrice2(ds);
}

OP *VM2Factory::createOP()
{
    OP *op = new OP();
    op->setCreateMsg(createCreateMsg());
    op->setDisposeDrink(createDisposeDrink());
    op->setDisposeAdditives(createDisposeAdditives());
    op->setSetPrice(createSetPrice());
    op->setReturnCoins(createReturnCoins());
    op->setStorePrice(createStorePrice());
    return op;
}
