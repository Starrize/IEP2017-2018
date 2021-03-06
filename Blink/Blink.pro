#-------------------------------------------------
#
# Project created by QtCreator 2017-10-18T16:29:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Blink
TEMPLATE = app


SOURCES += main.cpp\
    bcm2835_stub.cpp \
    pin.cpp \
    pwm.cpp \
    spi.cpp \
    serial.cpp

HEADERS  += \
    bcm2835.h \
    pin.h \
    pwm.h \
    spi.h \
    serial.h

FORMS    += blink.ui
