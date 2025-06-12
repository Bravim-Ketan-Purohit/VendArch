#ifndef VM2FACTORY_H
#define VM2FACTORY_H

#include "AbstractFactory.h"
#include "../model/DS2.h" // ✅ for int-based datastore

class VM2Factory : public AbstractFactory
{
private:
    DataStore *ds; // Shared DS2 instance

public:
    VM2Factory();

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
