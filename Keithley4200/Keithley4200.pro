#-------------------------------------------------
#
# Project created by QtCreator 2017-09-25T10:34:45
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = Keithley4200
TEMPLATE = lib

DEFINES += KEITHLEY4200_LIBRARY

SOURCES += Keithley4200.cpp \
    Keithley4200ChannelDefinitionPage.cpp \
    IKeithley4200Page.cpp \
    Keithley4200SourceSetupPage.cpp \
    Keithley4200MeasurementSetupPage.cpp \
    Keithley4200MeasurementControlPage.cpp

HEADERS += Keithley4200.h\
        keithley4200_global.h \
    Keithley4200ChannelDefinitionPage.h \
    IKeithley4200Page.h \
    Keithley4200SourceSetupPage.h \
    Keithley4200MeasurementSetupPage.h \
    Keithley4200Definitions.h \
    Keithley4200MeasurementControlPage.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DeviceIO/DeviceIO/release/ -lDeviceIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DeviceIO/DeviceIO/debug/ -lDeviceIO
else:unix: LIBS += -L$$OUT_PWD/../DeviceIO/DeviceIO/ -lDeviceIO

INCLUDEPATH += $$PWD/../DeviceIO/DeviceIO
DEPENDPATH += $$PWD/../DeviceIO/DeviceIO

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SourceMeterUnit/SourceMeterUnit/release/ -lSourceMeterUnit
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SourceMeterUnit/SourceMeterUnit/debug/ -lSourceMeterUnit
else:unix: LIBS += -L$$OUT_PWD/../SourceMeterUnit/SourceMeterUnit/ -lSourceMeterUnit

INCLUDEPATH += $$PWD/../SourceMeterUnit/SourceMeterUnit
DEPENDPATH += $$PWD/../SourceMeterUnit/SourceMeterUnit
