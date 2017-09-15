QT += core
QT -= gui

CONFIG += c++11

TARGET = TestApp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/release/ -lDeviceIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/debug/ -lDeviceIO

INCLUDEPATH += $$PWD/../../DeviceIO/DeviceIO
DEPENDPATH += $$PWD/../../DeviceIO/DeviceIO


win32: LIBS += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\lib\msc\visa32.lib"
win32: INCLUDEPATH += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Include"
