#ifndef CREATEMSG_H
#define CREATEMSG_H

class CreateMsg
{
public:
    virtual void create_msg() = 0;  // Pure virtual method
    virtual ~CreateMsg() = default; // Required for safe inheritance
};

#endif
