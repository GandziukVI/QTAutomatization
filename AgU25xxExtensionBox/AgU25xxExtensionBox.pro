#-------------------------------------------------
#
# Project created by QtCreator 2018-01-03T09:39:03
#
#-------------------------------------------------

QT       -= gui

TARGET = AgU25xxExtensionBox
TEMPLATE = lib

DEFINES += AGU25XXEXTENSIONBOX_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        AgU25xxExtensionBox.cpp \
    Filter.cpp \
    GainAmplifier.cpp \
    AgU25xxExtBoxException.cpp \
    AnalogInLatch.cpp \
    AnalogOutLatch.cpp \
    AIChannelModeSwitch.cpp

HEADERS += \
        AgU25xxExtensionBox.h \
        agu25xxextensionbox_global.h \ 
    AgU25xxExtBoxDefinitions.h \
    Filter.h \
    GainAmplifier.h \
    AgU25xxExtBoxException.h \
    ilatch.h \
    AnalogInLatch.h \
    AnalogOutLatch.h \
    AIChannelModeSwitch.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DeviceIO/DeviceIO/release/ -lDeviceIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DeviceIO/DeviceIO/debug/ -lDeviceIO

INCLUDEPATH += $$PWD/../DeviceIO/DeviceIO
DEPENDPATH += $$PWD/../DeviceIO/DeviceIO

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AgilentU25xx/AgilentU25xx/release/ -lAgilentU25xx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AgilentU25xx/AgilentU25xx/debug/ -lAgilentU25xx

INCLUDEPATH += $$PWD/../AgilentU25xx/AgilentU25xx
DEPENDPATH += $$PWD/../AgilentU25xx/AgilentU25xx
