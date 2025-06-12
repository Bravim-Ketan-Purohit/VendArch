// File: strategy/CardPayment.h
// Purpose: Concrete strategy for card payment logic

#ifndef CARD_PAYMENT_H
#define CARD_PAYMENT_H

#include "PaymentStrategy.h"

class CardPayment : public PaymentStrategy
{
public:
    bool pay(DataStore *ds, float amount) override;
};

#endif
