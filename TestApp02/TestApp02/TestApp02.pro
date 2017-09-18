QT += core
QT -= gui

CONFIG += c++11

TARGET = TestApp02
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    VisaDevice.cpp

HEADERS += \
    VisaDevice.h \
    IDeviceIO.h

win32: LIBS += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\lib\msc\visa32.lib"
win32: INCLUDEPATH += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Include"
