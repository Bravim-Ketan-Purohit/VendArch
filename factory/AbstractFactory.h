#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H

// Forward declarations
class DataStore;
class CreateMsg;
class DisposeDrink;
class DisposeAdditives;
class SetPrice;
class ReturnCoins;
class StorePrice;
class OP;
class PaymentStrategy;

class AbstractFactory
{
public:
    // Data
    virtual DataStore *createDataStore() = 0;

    // Payment strategies
    virtual PaymentStrategy *createCoinPaymentStrategy() = 0;
    virtual PaymentStrategy *createCardPaymentStrategy() = 0;

    // Output strategies
    virtual CreateMsg *createCreateMsg() = 0;
    virtual DisposeDrink *createDisposeDrink() = 0;
    virtual DisposeAdditives *createDisposeAdditives() = 0;
    virtual SetPrice *createSetPrice() = 0;
    virtual ReturnCoins *createReturnCoins() = 0;
    virtual StorePrice *createStorePrice() = 0;

    // Output processor (Strategy router)
    virtual OP *createOP() = 0;

    virtual ~AbstractFactory() = default;
};

#endif
