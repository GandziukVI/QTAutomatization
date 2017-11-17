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
    AgU25xxOUTPutSubSys.cpp \
    AgU25xxACQuireSubSys.cpp \
    AgU25xxAPPLySubSys.cpp \
    AgU25xxCONFigureSubSys.cpp \
    AgU25xxCALibrationSubSys.cpp \
    AgU25xxMEASureSubSys.cpp \
    AgU25xxROUTeSubSys.cpp \
    AgU25xxSENSeSubSys.cpp \
    IAgU25xxSubsystemExtensions.cpp \
    AgU25xxSOURceSubSys.cpp \
    AgU25xxTRIGgerSubSys.cpp \
    AgU25xxSYSTemSubSys.cpp \
    AgU25xxWAVeformSubSys.cpp \
    AgU25xxRootCommands.cpp \
    AgU25xxAIChannel.cpp \
    AgU25xxException.cpp \
    AgU25xxAIChannelSet.cpp \
    AgU25xxAOChannel.cpp \
    AgU25xxAOChannelSet.cpp \
    AgU25xxDIGChannel.cpp \
    AgU25xxDIGitalBit.cpp \
    AgU25xxDIGitalChannelSet.cpp

HEADERS += AgilentU25xx.h\
        agilentu25xx_global.h \
    IAgU25xxSubsystem.h \
    AgU25xxDefinitions.h \
    AgU25xxOUTPutSubSys.h \
    AgU25xxACQuireSubSys.h \
    AgU25xxAPPLySubSys.h \
    AgU25xxCALibrationSubSys.h \
    AgU25xxCONFigureSubSys.h \
    AgU25xxMEASureSubSys.h \
    AgU25xxROUTeSubSys.h \
    AgU25xxSENSeSubSys.h \
    IAgU25xxSubsystemExtensions.h \
    AgU25xxSOURceSubSys.h \
    AgU25xxTRIGgerSubSys.h \
    AgU25xxSYSTemSubSys.h \
    AgU25xxWAVeformSubSys.h \
    AgU25xxRootCommands.h \
    AgU25xxAIChannel.h \
    AgU25xxException.h \
    AgU25xxAIChannelSet.h \
    AgU25xxAOChannel.h \
    AgU25xxAOChannelSet.h \
    AgU25xxDIGChannel.h \
    AgU25xxDIGitalBit.h \
    AgU25xxDIGitalChannelSet.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/release/ -lDeviceIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../DeviceIO/DeviceIO/debug/ -lDeviceIO

INCLUDEPATH += $$PWD/../../DeviceIO/DeviceIO
DEPENDPATH += $$PWD/../../DeviceIO/DeviceIO
