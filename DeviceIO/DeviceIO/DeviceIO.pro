#-------------------------------------------------
#
# Project created by QtCreator 2017-09-14T14:13:09
#
#-------------------------------------------------

QT       -= gui

TARGET = DeviceIO
TEMPLATE = lib

DEFINES += DEVICEIO_LIBRARY

SOURCES += VisaDevice.cpp \
    SerialDevice.cpp

HEADERS += VisaDevice.h\
        deviceio_global.h \
    IDeviceIO.h \
    SerialDevice.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32: LIBS += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\lib\msc\visa32.lib"
win32: INCLUDEPATH += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Include"
