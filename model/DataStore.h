// File: model/DataStore.h
// Purpose: Abstract base class for data storage used in platform-independent state machine logic.
// All state and strategy logic should interact with this interface only.

#ifndef DATASTORE_H
#define DATASTORE_H

class DataStore
{
public:
    virtual ~DataStore() {}

    // Payment-related values
    virtual float get_cf() = 0;
    virtual void set_cf(float value) = 0;

    virtual float get_price() = 0;
    virtual void set_price(float value) = 0;

    virtual float get_temp_p() = 0;
    virtual void set_temp_p(float value) = 0;

    // Cup count
    virtual int get_k() = 0;
    virtual void set_k(int value) = 0;

    // Additive tracking (e.g., sugar, cream) via index
    virtual int get_additive(int index) = 0;
    virtual void set_additive(int index, int value) = 0;
};

#endif // DATASTORE_H
