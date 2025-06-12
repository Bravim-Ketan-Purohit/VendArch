// File: model/VM_1.h
// Purpose: Interface for Vending Machine 1 (VM_1)
// VM_1 is a float-based vending machine that delegates pricing,
// coin/card payments, and refunding to strategy classes.
// It maintains a reference to the MDA_EFSM and its associated DataStore (DS1).

#ifndef VM_1_H
#define VM_1_H

#include <string>

// Forward declarations
class AbstractFactory;
class MDA_EFSM;
class DataStore;
class PaymentStrategy;
class OP;

class VM_1
{
private:
    DataStore *ds;  // Shared DataStore (DS1)
    MDA_EFSM *efsm; // MDA-EFSM state manager
    PaymentStrategy *coinPayment;
    PaymentStrategy *cardPayment;

public:
    VM_1(AbstractFactory *factory);
    ~VM_1();

    // Business logic methods
    void create(float price); // Initializes machine with price
    void insert_cups(int n);  // Adds cups to machine
    void coin(float v);       // Process coin payment
    void card(float x);       // Process card payment
    void set_price(float p);  // Update price
    void sugar();             // Add sugar to drink
    void cappuccino();        // Dispense cappuccino
    void chocolate();         // Dispense chocolate
    void cancel();            // Cancel current transaction

    // Returns the current EFSM state name
    std::string getStateName();
};

#endif
