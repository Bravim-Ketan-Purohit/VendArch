// File: model/DS1.h
// Purpose: Concrete DataStore implementation for VM_1 (float-based machine)

#ifndef DS1_H
#define DS1_H

#include "DataStore.h"

class DS1 : public DataStore
{
private:
    float temp_p = 0.0f;
    float price = 0.0f;
    float cf = 0.0f;
    int k = 0;      // Number of cups
    int A[2] = {0}; // Additives: A[0]=sugar, A[1]=cream (only A[0] used in VM_1)

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

#endif // DS1_H
