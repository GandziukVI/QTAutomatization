QT += qml quick charts

SOURCES += \
    main.cpp \
    qmlBackEnd/NoiseFETModel.cpp \
    IExperiment.cpp \
    experiments/NoiseFETExperiment.cpp \
    NoiseFETException.cpp

DISTFILES += \
    qml/main.qml \
    qml/CTextArea.qml \
    qml/CTextAreaRealArray.qml \
    qml/CTextArea.qml \
    qml/CTextAreaRealArray.qml \
    qml/VoltageRangeSetter.qml \
    qml/CTextField.qml \
    qml/CExtendedNumberInput.qml \
    qml/ExtBoxAIChannelParams.qml \
    js/CTextAreaArray.js \
    js/QMLChartViewLogic.js

RESOURCES += \
    resources.qrc

HEADERS += \
    qmlBackEnd/NoiseFETModel.h \
    ffft/Array.h \
    ffft/Array.hpp \
    ffft/def.h \
    ffft/DynArray.h \
    ffft/DynArray.hpp \
    ffft/FFTReal.h \
    ffft/FFTReal.hpp \
    ffft/OscSinCos.h \
    ffft/OscSinCos.hpp \
    IExperiment.h \
    experiments/NoiseFETExperiment.h \
    NoiseFETException.h

win32: LIBS += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\lib\msc\visa32.lib"
win32: INCLUDEPATH += "C:\Program Files (x86)\IVI Foundation\VISA\WinNT\Include"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../DeviceIO/DeviceIO/release/ -lDeviceIO
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../DeviceIO/DeviceIO/debug/ -lDeviceIO

INCLUDEPATH += $$PWD/../DeviceIO/DeviceIO
DEPENDPATH += $$PWD/../DeviceIO/DeviceIO

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AgilentU25xx/AgilentU25xx/release/ -lAgilentU25xx
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AgilentU25xx/AgilentU25xx/debug/ -lAgilentU25xx

INCLUDEPATH += $$PWD/../AgilentU25xx/AgilentU25xx
DEPENDPATH += $$PWD/../AgilentU25xx/AgilentU25xx

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AgU25xxExtensionBox/release/ -lAgU25xxExtensionBox
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AgU25xxExtensionBox/debug/ -lAgU25xxExtensionBox

INCLUDEPATH += $$PWD/../AgU25xxExtensionBox
DEPENDPATH += $$PWD/../AgU25xxExtensionBox
