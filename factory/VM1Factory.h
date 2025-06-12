#ifndef VM1FACTORY_H
#define VM1FACTORY_H

#include "AbstractFactory.h"
#include "../model/DataStore.h" // ✅ Include full definition

// Forward declarations
class CreateMsg;
class DisposeDrink;
class DisposeAdditives;
class SetPrice;
class ReturnCoins;
class StorePrice;
class OP;
class PaymentStrategy;

#include "../model/DataStore.h"

class VM1Factory : public AbstractFactory
{
private:
    DataStore *ds; // ✅ shared DS1 instance
public:
    VM1Factory();

    DataStore *createDataStore() override;
    PaymentStrategy *createCoinPaymentStrategy() override;
    PaymentStrategy *createCardPaymentStrategy() override;

    CreateMsg *createCreateMsg() override;
    DisposeDrink *createDisposeDrink() override;
    DisposeAdditives *createDisposeAdditives() override;
    SetPrice *createSetPrice() override;
    ReturnCoins *createReturnCoins() override;
    StorePrice *createStorePrice() override;

    OP *createOP() override;
};

#endif
