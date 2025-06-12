#ifndef DISPOSEADDITIVES2_H
#define DISPOSEADDITIVES2_H

#include "DisposeAdditives.h"
#include "../model/DataStore.h"

class DisposeAdditives2 : public DisposeAdditives
{
private:
    DataStore *ds;

public:
    DisposeAdditives2(DataStore *datastore);
    void dispose_additives() override;
};

#endif
