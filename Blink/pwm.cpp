#include "pwm.h"
#include "bcm2835.h"

#define PIN RPI_GPIO_P1_12
#define PWM_CHANNEL 0

PWM::PWM(int frequency, int dutyCycle){
    this->frequency = frequency;
    this->dutyCycle = dutyCycle;
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    bcm2835_pwm_set_range(PWM_CHANNEL, this->frequency);

    int data = this->dutyCycle * this->frequency / 100;
    bcm2835_pwm_set_data(PWM_CHANNEL, data);
}
int PWM::getDutyCycle(){
    return dutyCycle;
}
int PWM::getFrequency(){
    return frequency;
}
void PWM::setDutyCycle(int dutyCycle){
    this->dutyCycle = dutyCycle;

    int data = dutyCycle * this->frequency / 100;
    bcm2835_pwm_set_data(PWM_CHANNEL, data);
}
void PWM::setFrequency(int frequency){
    this->frequency = frequency;
    bcm2835_pwm_set_range(PWM_CHANNEL, this->frequency);
}
