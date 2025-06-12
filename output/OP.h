#ifndef OP_H
#define OP_H

// Forward declarations
class CreateMsg;
class DisposeDrink;
class DisposeAdditives;
class SetPrice;
class ReturnCoins;
class StorePrice;

class OP
{
private:
    CreateMsg *createMsg;
    DisposeDrink *disposeDrink;
    DisposeAdditives *disposeAdditives;
    SetPrice *setPrice;
    ReturnCoins *returnCoins;
    StorePrice *storePrice;

public:
    // Setters for each strategy
    void setCreateMsg(CreateMsg *c);
    void setDisposeDrink(DisposeDrink *d);
    void setDisposeAdditives(DisposeAdditives *a);
    void setSetPrice(SetPrice *s);
    void setReturnCoins(ReturnCoins *r);
    void setStorePrice(StorePrice *s);

    // Runtime triggers
    void create();
    void dispose_drink();
    void dispose_additives();
    void set_price(float price);
    void return_coins();
    void store_price(); // ✅ No parameters now
};

#endif
