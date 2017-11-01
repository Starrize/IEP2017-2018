#ifndef PWM_H
#define PWM_H

class PWM{
public:
    PWM(int frequency, int dutyCycle);
    int frequency;
    int dutyCycle;
    int getFrequency();
    void setFrequency(int frequency);
    int getDutyCycle();
    void setDutyCycle(int dutyCycle);
};

#endif // PWM_H
