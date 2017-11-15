#include <bcm2835.h>
#ifndef SERIAL_H
#define SERIAL_H


class Serial
{
public:
    virtual uint8_t transfer(uint8_t send_data) = 0;
};

#endif // SERIAL_H
