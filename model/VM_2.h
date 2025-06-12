// File: model/VM_2.h
// Purpose: Declaration of VM_2, the integer-based vending machine controller.
// Responsibilities:
// - Defines public interface for VM2 user operations
// - Delegates events to EFSM
// - Uses AbstractFactory to obtain DS2 and strategy objects

#ifndef VM_2_H
#define VM_2_H

#include "../model/DataStore.h"
#include "../model/DS2.h"
#include "../model/MDA_EFSM.h"
#include "../factory/AbstractFactory.h"

class VM_2
{
private:
    MDA_EFSM *mda;       // EFSM instance for managing state transitions
    AbstractFactory *af; // Factory for dependency injection
    DataStore *ds;       // Shared DataStore reference

public:
    VM_2(AbstractFactory *factory);
    void CREATE(int p);
    void COIN(int v);
    void CARD(int x);
    void SUGAR();
    void CREAM();
    void COFFEE();
    void InsertCups(int n);
    void SetPrice(int p);
    void CANCEL();
    std::string getStateName();
    ~VM_2();
};

#endif
