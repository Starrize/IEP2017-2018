#include "spi.h"

spi::spi(int order, int mode, int divider, int cs, int polarity){
    bcm2835_spi_setBitOrder(order);
    bcm2835_spi_setDataMode(mode);
    bcm2835_spi_setClockDivider(divider);
    bcm2835_spi_chipSelect(cs);
    bcm2835_spi_setChipSelectPolarity(cs, polarity);
}

uint8_t spi::transfer(uint8_t send_data){
    return bcm2835_spi_transfer(send_data);
}
