#ifndef PIN_H
#define PIN_H


class Pin
{
public:
    Pin(int pinNr);
    double get();
    void set();
    void changeDirection();

private:
    int pinNr;
    int direction;
};

#endif // PIN_H
