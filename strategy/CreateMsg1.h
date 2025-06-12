// File: strategy/CreateMsg1.h
// Purpose: Concrete strategy for printing VM1 creation message

#ifndef CREATE_MSG_1_H
#define CREATE_MSG_1_H

#include "CreateMsg.h"
#include "../model/DataStore.h"

class CreateMsg1 : public CreateMsg
{
private:
    DataStore *ds;

public:
    CreateMsg1(DataStore *ds) : ds(ds) {}
    void create_msg() override;
};

#endif
