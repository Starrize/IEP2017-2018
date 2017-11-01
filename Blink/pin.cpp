#include "pin.h"
#include "bcm2835.h"

Pin::Pin(int pinNr, int direction, int state)
{
          this->pinNr=pinNr;
          this->direction=direction;
          this->state=state;
          bcm2835_gpio_fsel(pinNr, direction);
}

void Pin::set(int p){
     if(this->direction==0){
          bcm2835_gpio_write(this->pinNr, p);
     }
}

int Pin::get(){
     int res;
    if(this->direction == 0){
        res = this->state;
    }
    else{
        res  = bcm2835_gpio_lev(this->pinNr);
    }
    return res;
}
void Pin::change(){
    if(this->direction==0){
        bcm2835_gpio_fsel(this->pinNr, BCM2835_GPIO_FSEL_INPT);
    }
    else{
        bcm2835_gpio_fsel(this->pinNr, BCM2835_GPIO_FSEL_OUTP);
    }
}
