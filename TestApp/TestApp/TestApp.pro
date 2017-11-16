QT += core
QT -= gui

CONFIG += c++11

TARGET = TestApp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32: LIBS += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\lib\msc\visa32.lib"
win32: INCLUDEPATH += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Include"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/release/ -lDeviceIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/debug/ -lDeviceIO
else:unix: LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/ -lDeviceIO

INCLUDEPATH += $$PWD/../../DeviceIO/DeviceIO
DEPENDPATH += $$PWD/../../DeviceIO/DeviceIO

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../SourceMeterUnit/SourceMeterUnit/release/ -lSourceMeterUnit
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../SourceMeterUnit/SourceMeterUnit/debug/ -lSourceMeterUnit
else:unix: LIBS += -L$$OUT_PWD/../../SourceMeterUnit/SourceMeterUnit/ -lSourceMeterUnit

INCLUDEPATH += $$PWD/../../SourceMeterUnit/SourceMeterUnit
DEPENDPATH += $$PWD/../../SourceMeterUnit/SourceMeterUnit

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Keithley4200/release/ -lKeithley4200
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Keithley4200/debug/ -lKeithley4200
else:unix: LIBS += -L$$OUT_PWD/../../Keithley4200/ -lKeithley4200

INCLUDEPATH += $$PWD/../../Keithley4200
DEPENDPATH += $$PWD/../../Keithley4200

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../AgilentU25xx/AgilentU25xx/release/ -lAgilentU25xx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../AgilentU25xx/AgilentU25xx/debug/ -lAgilentU25xx

INCLUDEPATH += $$PWD/../../AgilentU25xx/AgilentU25xx
DEPENDPATH += $$PWD/../../AgilentU25xx/AgilentU25xx
