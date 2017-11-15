#-------------------------------------------------
#
# Project created by QtCreator 2017-11-15T14:04:41
#
#-------------------------------------------------

QT       -= gui

TARGET = AgilentU25xx
TEMPLATE = lib

DEFINES += AGILENTU25XX_LIBRARY

SOURCES += AgilentU25xx.cpp \
    IAgU25xxSubsystem.cpp \
    AgU25xxACQuire.cpp \
    AgU25xxAPPLy.cpp \
    AgU25xxCALibration.cpp \
    AgU25xxCONFigure.cpp \
    AgU25xxMEASure.cpp

HEADERS += AgilentU25xx.h\
        agilentu25xx_global.h \
    IAgU25xxSubsystem.h \
    AgU25xxACQuire.h \
    AgU25xxAPPLy.h \
    AgU25xxDefinitions.h \
    AgU25xxCALibration.h \
    AgU25xxCONFigure.h \
    AgU25xxMEASure.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/release/ -lDeviceIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/debug/ -lDeviceIO

INCLUDEPATH += $$PWD/../../DeviceIO/DeviceIO
DEPENDPATH += $$PWD/../../DeviceIO/DeviceIO
