QT += qml quick charts

SOURCES += \
    main.cpp \
    qmlBackEnd/NoiseFETModel.cpp

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
    qmlBackEnd/NoiseFETModel.h
