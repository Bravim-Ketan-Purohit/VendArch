#ifndef DISPOSEADDITIVES1_H
#define DISPOSEADDITIVES1_H

#include "DisposeAdditives.h"
#include "../model/DataStore.h"

class DisposeAdditives1 : public DisposeAdditives
{
private:
    DataStore *ds;

public:
    DisposeAdditives1(DataStore *datastore);
    void dispose_additives() override;
};

#endif
