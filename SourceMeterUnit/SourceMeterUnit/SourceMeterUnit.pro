#-------------------------------------------------
#
# Project created by QtCreator 2017-09-21T14:31:00
#
#-------------------------------------------------

QT       -= gui

TARGET = SourceMeterUnit
TEMPLATE = lib

DEFINES += SOURCEMETERUNIT_LIBRARY

SOURCES += \
    SourceMeterUnitDefinitions.cpp \
    SourceMeterUnitExtensions.cpp

HEADERS += ISourceMeterUnit.h\
        sourcemeterunit_global.h \
    SourceMeterUnitDefinitions.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/release/ -lDeviceIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/debug/ -lDeviceIO

INCLUDEPATH += $$PWD/../../DeviceIO/DeviceIO
DEPENDPATH += $$PWD/../../DeviceIO/DeviceIO
