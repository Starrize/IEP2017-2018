/*// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
#include <bcm2835.h>
#include <stdio.h>
#include "pin.h"
// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
    bcm2835_set_debug(1);
    if (!bcm2835_init())
      return 1;
    Pin *pin = new Pin(PIN,BCM2835_GPIO_FSEL_OUTP,0);
    // Set the pin to be an output

    // Blink
    while (1)
    {
        pin->set(HIGH);

        bcm2835_delay(500);

        // turn it off
        pin->set(LOW);
        // wait a bit
        bcm2835_delay(500);
    }
    bcm2835_close();
    return 0;
}
*/

// pwm.c
//
// Example program for bcm2835 library
// Shows how to use PWM to control GPIO pins
//
// After installing bcm2835, you can build this
// with something like:
// gcc -o pwm pwm.c -l bcm2835
// sudo ./pwm
//
// Or you can test it before installing with:
// gcc -o pwm -I ../../src ../../src/bcm2835.c pwm.c
// sudo ./pwm
//
// Connect an LED between GPIO18 (pin 12) and GND to observe the LED changing in brightness
//
// Author: Mike McCauley
// Copyright (C) 2013 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
#include <bcm2835.h>
#include <stdio.h>
#include "pin.h"
#include "pwm.h"

// PWM output on RPi Plug P1 pin 12 (which is GPIO pin 18)
// in alt fun 5.
// Note that this is the _only_ PWM pin available on the RPi IO headers
#define PIN RPI_GPIO_P1_12
// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 1024
int main(int argc, char **argv)
{
    Pin *pin = new Pin(PIN,BCM2835_GPIO_FSEL_OUTP,0);
    PWM *pwm = new PWM(1024, 0);
    if (!bcm2835_init())
        return 1;

    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_ALT5);

    while (1)
    {
        if(pwm->getDutyCycle() < 100){
            pwm->setDutyCycle(pwm->getDutyCycle()+10);
        }else{
            pwm->setDutyCycle(0);
        }
        bcm2835_delay(1);
/*
        if (data == 100)
            direction = 1;   // Switch to increasing
        else if (data == RANGE-1)
            direction = -1;  // Switch to decreasing
        data += direction;

        bcm2835_pwm_set_data(PWM_CHANNEL, data);
        bcm2835_delay(1);*/
    }
    bcm2835_close();
    return 0;
}
