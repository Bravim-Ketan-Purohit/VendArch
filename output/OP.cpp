#include <iostream>

#include "OP.h"
#include "../strategy/CreateMsg.h"
#include "../strategy/DisposeDrink.h"
#include "../strategy/DisposeAdditives.h"
#include "../strategy/SetPrice.h"
#include "../strategy/ReturnCoins.h"
#include "../strategy/StorePrice.h"
using namespace std;
// Setters
void OP::setCreateMsg(CreateMsg *c)
{
    createMsg = c;
}

void OP::setDisposeDrink(DisposeDrink *d)
{
    disposeDrink = d;
}

void OP::setDisposeAdditives(DisposeAdditives *a)
{
    disposeAdditives = a;
}

void OP::setSetPrice(SetPrice *s)
{
    setPrice = s;
}

void OP::setReturnCoins(ReturnCoins *r)
{
    returnCoins = r;
}

void OP::setStorePrice(StorePrice *s)
{
    storePrice = s;
}

// Execution triggers
void OP::create()
{
    if (createMsg)
        createMsg->create_msg();
}

void OP::dispose_drink()
{
    if (disposeDrink)
        disposeDrink->dispose_drink();
}

void OP::dispose_additives()
{
    if (disposeAdditives)
        disposeAdditives->dispose_additives();
}

void OP::set_price(float price)
{
    if (setPrice)
        setPrice->set_price(price);
}

void OP::return_coins()
{
    if (returnCoins)
        returnCoins->return_coins();
}

void OP::store_price()
{
    if (storePrice)
        storePrice->storePrice(); // ✅ match interface
    else
        cout << "[OP] StorePrice not configured.\n";
}
