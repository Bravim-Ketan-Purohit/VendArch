// File: model/DS2.h
// Purpose: Concrete DataStore implementation for VM_2 (int-based machine)

#ifndef DS2_H
#define DS2_H

#include "DataStore.h"

class DS2 : public DataStore
{
private:
    int temp_p = 0;
    int price = 0;
    int cf = 0;
    int k = 0;
    int A[2] = {0}; // A[0] = sugar, A[1] = cream

public:
    float get_cf() override;
    void set_cf(float value) override;

    float get_price() override;
    void set_price(float value) override;

    float get_temp_p() override;
    void set_temp_p(float value) override;

    int get_k() override;
    void set_k(int value) override;

    int get_additive(int index) override;
    void set_additive(int index, int value) override;
};

#endif // DS2_H
