QT += qml quick charts

SOURCES += \
    main.cpp \
    qmlBackEnd/NoiseFETModel.cpp \
    IExperiment.cpp \
    experiments/NoiseFETExperiment.cpp

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
    experiments/NoiseFETExperiment.h
