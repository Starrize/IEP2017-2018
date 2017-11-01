#ifndef PIN_H
#define PIN_H


 class Pin
{
 public:
     Pin(int pinNr,int direction,int state);
     int pinNr;
     int direction;
     int state;
     int get();
     void set(int p);
     void change();
 };
 #endif
