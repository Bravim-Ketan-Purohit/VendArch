// File: model/DS1.cpp
// Purpose: Implements all virtual methods defined in DataStore for VM_1 (float-based)

#include "DS1.h"

float DS1::get_cf() { return cf; }
void DS1::set_cf(float value) { cf = value; }

float DS1::get_price() { return price; }
void DS1::set_price(float value) { price = value; }

float DS1::get_temp_p() { return temp_p; }
void DS1::set_temp_p(float value) { temp_p = value; }

int DS1::get_k() { return k; }
void DS1::set_k(int value) { k = value; }

int DS1::get_additive(int index)
{
    if (index >= 0 && index < 2)
        return A[index];
    return 0;
}
void DS1::set_additive(int index, int value)
{
    if (index >= 0 && index < 2)
        A[index] = value;
}
