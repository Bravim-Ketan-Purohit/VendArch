#include "StorePrice.h" // ✅ This defines the full base class
#include "../model/DataStore.h"

class StorePrice1 : public StorePrice
{
private:
    DataStore *ds;

public:
    StorePrice1(DataStore *datastore); // Constructor injection
    void storePrice() override;
};
