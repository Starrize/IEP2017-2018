#include "pin.h"

Pin::Pin(int pinNr)
{
     this->pinNr = pinNr;
}
Pin::get(){
    return bcm2835_gpio_lev(pinNr);
}
Pin::set(int highlow){
    /**
    * 1 - input
    * 0 - output
    *
    */
    if(direction == 1){

    }
    else{
       if(highlow == 0){
            bcm2835_gpio_clr(pinNr);
       }
       else{
           bcm2835_gpio_set(pinNr);
       }
    }
}
Pin::changeDirection(int pud){
    void bcm2835_gpio_set_pud(pinNr, pud);
}
