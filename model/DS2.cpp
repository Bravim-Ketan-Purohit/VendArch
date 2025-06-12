// File: model/DS2.cpp
// Purpose: Implements DataStore for VM_2 with integer logic and float interface conformance

#include "DS2.h"

float DS2::get_cf() { return static_cast<float>(cf); }
void DS2::set_cf(float value) { cf = static_cast<int>(value); }

float DS2::get_price() { return static_cast<float>(price); }
void DS2::set_price(float value) { price = static_cast<int>(value); }

float DS2::get_temp_p() { return static_cast<float>(temp_p); }
void DS2::set_temp_p(float value) { temp_p = static_cast<int>(value); }

int DS2::get_k() { return k; }
void DS2::set_k(int value) { k = value; }

int DS2::get_additive(int index)
{
    if (index >= 0 && index < 2)
        return A[index];
    return 0;
}
void DS2::set_additive(int index, int value)
{
    if (index >= 0 && index < 2)
        A[index] = value;
}
