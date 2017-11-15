#include <bcm2835.h>
#include <stdio.h>
#include <spi.h>
int main(int argc, char **argv)
{
    bcm2835_set_debug(1);
    if (!bcm2835_init())
    {
      printf("bcm2835_init failed. Are you running as root??\n");
      return 1;
    }
    if (!bcm2835_spi_begin())
    {
      printf("bcm2835_spi_begin failed. Are you running as root??\n");
      return 1;
    }

    spi *obj = new spi(BCM2835_SPI_BIT_ORDER_MSBFIRST, BCM2835_SPI_MODE0, BCM2835_SPI_CLOCK_DIVIDER_65536, BCM2835_SPI_CS0, LOW);
    uint8_t send_data = 0x23;
    uint8_t read_data = obj->transfer(send_data);


    printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", send_data, read_data);
    if (send_data != read_data)
      printf("Do you have the loopback from MOSI to MISO connected?\n");
    bcm2835_spi_end();
    bcm2835_close();
    return 0;
}
