import QtQuick 2.2
import QtCharts 2.2
import QtQuick.Controls 2.2

import QtQuick.Layouts 1.3

Item {
    id: root
    width: 1280
    height: 720

    MouseArea {
        anchors.fill: parent
    }

    GridLayout {
        anchors.fill: parent
        anchors.margins: 10

        columns: 2

        ChartView {
            id: noiseFETChart
            legend.visible: false

            theme: ChartView.ChartThemeBlueCerulean

            Layout.fillWidth: true
            Layout.fillHeight: true

            LineSeries {
                id: nosieFETLineGraph

                axisX: LogValueAxis {
                    id: noiseFETFrequencyAxis
                    min: 0.5
                    max: 500000
                    titleText: qsTr("Frequency (Hz)")
                }

                axisY: LogValueAxis {
                    id: noiseFETNoisePSDAxis
                    labelFormat: qsTr("%.3e")
                    min: 1.0e-19
                    max: 1.0e-7
                    titleText: qsTr("<p>Noise PSD (V<sup>2</sup> / Hz)</p>")
                }
            }
        }

        Item {
            Layout.preferredWidth: 400
            Layout.maximumWidth: 400

            Layout.fillWidth: true
            Layout.fillHeight: true

            ColumnLayout {
                anchors.fill: parent

                Item {
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    id: noiseFETSettings

                    ScrollView {
                        anchors.fill: parent
                        clip: true

                        GridLayout {
                            width: noiseFETSettings.width
                            height: children.height

                            columns: 2

                            // Agilent U2542A resource name
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("Agilent U2542A res.")
                            }
                            CTextArea {
                                Layout.fillWidth: true
                                text: qsTr("USB0::2391::5912::TW54334510::INSTR")

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.agilentU2542ARes;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.agilentU2542ARes = text;
                                    }
                                }
                            }

                            GroupBox {
                                Layout.columnSpan: 2
                                Layout.fillWidth: true

                                title: qsTr("Measurement Mode")

                                ColumnLayout {
                                    RadioButton {
                                        text: qsTr("Transfer Curve")
                                        checked: true

                                        Component.onCompleted: {
                                            if (typeof noiseFETSettingsModel !== "undefined") {
                                                checked = noiseFETSettingsModel.isTransferCurveMode;
                                            }
                                        }
                                        onCheckedChanged: {
                                            if (typeof noiseFETSettingsModel !== "undefined") {
                                                noiseFETSettingsModel.isTransferCurveMode = checked;
                                            }
                                        }
                                    }
                                    RadioButton {
                                        text: qsTr("Output Curve")

                                        Component.onCompleted: {
                                            if (typeof noiseFETSettingsModel !== "undefined") {
                                                checked = noiseFETSettingsModel.isOutputCurveMode;
                                            }
                                        }
                                        onCheckedChanged: {
                                            if (typeof noiseFETSettingsModel !== "undefined") {
                                                noiseFETSettingsModel.isOutputCurveMode = checked;
                                            }
                                        }
                                    }
                                }
                            }

                            // Set of gate voltages
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("Gate Voltages")
                            }
                            CTextAreaRealArray {
                                Layout.fillWidth: true

                                id: gateVoltageValues
                                text: qsTr("[ 0.0 ]")

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        arrayElements = noiseFETSettingsModel.gateVoltages;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.gateVoltages = arrayElements;
                                    }
                                }
                            }
                            Button {
                                id: cmdSetVGRange

                                Layout.columnSpan: 2
                                Layout.fillWidth: true

                                text: qsTr("Set Gate Voltage Range")

                                onClicked: {
                                    var component = Qt.createComponent("VoltageRangeSetter.qml");
                                    var win = component.createObject(root);

                                    win.dataChanged.connect(setGateVoltageArray);

                                    win.show();
                                }
                            }

                            // Set of drain-source volatges
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("D-S Voltages")
                            }
                            CTextAreaRealArray {
                                Layout.fillWidth: true

                                id: drainVoltageValues
//                                text: qsTr("[0.0 ]")

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        arrayElements = noiseFETSettingsModel.drainVoltages;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.drainVoltages = arrayElements;
                                    }
                                }
                            }
                            Button {
                                id: cmdSetVDSRange

                                Layout.columnSpan: 2
                                Layout.fillWidth: true

                                text: qsTr("Set Drain Voltage Range")

                                onClicked: {
                                    var component = Qt.createComponent("VoltageRangeSetter.qml");
                                    var win = component.createObject(root);

                                    win.dataChanged.connect(setDrainVoltageArray);

                                    win.show();
                                }
                            }

                            // Allowed voltage deviation
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("Voltage Deviation")
                            }
                            CExtendedNumberInput {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("0.2")
                                validator: DoubleValidator { locale: qsTr("en_US") }
                                units: qsTr("V")

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        inputValue = noiseFETSettingsModel.voltageDeviationDisplay;
                                        multiplierIndex = noiseFETSettingsModel.voltageDeviationMultIndex;

                                        noiseFETSettingsModel.voltageDeviation = realValue;
                                    }
                                }

                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.voltageDeviationDisplay = inputValue;
                                        noiseFETSettingsModel.voltageDeviationMultIndex = multiplierIndex;
                                        noiseFETSettingsModel.voltageDeviation = realValue;
                                    }
                                }
                            }

                            // Fast averaging control
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("nAvg. fast")
                            }
                            CTextField {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("2")
                                validator: IntValidator { locale: qsTr("en_US") }

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.nAvgFast;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.nAvgFast = parseInt(text);
                                    }
                                }
                            }

                            // Slow averaging control
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("nAvg. slow")
                            }
                            CTextField {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("100")
                                validator: IntValidator { locale: qsTr("en_US") }

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.nAvgSlow;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.nAvgSlow = parseInt(text);
                                    }
                                }
                            }

                            // Stabilization time
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("Stabilization time")
                            }
                            CExtendedNumberInput {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("45")
                                validator: DoubleValidator { locale: qsTr("en_US") }
                                units: qsTr("s")

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.stabilizationTime;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.stabilizationTime = parseFloat(text);
                                    }
                                }
                            }

                            // Load resistance
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("Load resistance")
                            }
                            CTextField {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("5000.0")
                                validator: DoubleValidator { locale: qsTr("en_US") }

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.loadResistance;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.loadResistance = parseFloat(text);
                                    }
                                }
                            }

                            // Sampling frequency
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("Sampling frequency")
                            }
                            CTextField {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("262144")
                                validator: IntValidator { locale: qsTr("en_US") }

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.samplingFrequency;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.samplingFrequency = parseInt(text);
                                    }
                                }
                            }

                            // n Spectra avg.
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("n Spectra avg.")
                            }
                            CTextField {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("100")
                                validator: IntValidator { locale: qsTr("en_US") }

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.nSpectraAvg;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.nSpectraAvg = parseInt(text);
                                    }
                                }
                            }

                            // k Preamp
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("k pre-Amp.")
                            }
                            CTextField {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("178")
                                validator: DoubleValidator { locale: qsTr("en_US") }

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.kPreampl;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.kPreampl = parseFloat(text);
                                    }
                                }
                            }

                            // k Amp
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("k Amp.")
                            }
                            CTextField {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("100")
                                validator: DoubleValidator { locale: qsTr("en_US") }

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.kAmpl;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.kAmpl = parseFloat(text);
                                    }
                                }
                            }

                            // Temperature 0
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("Temperature 0")
                            }
                            CTextField {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("293")
                                validator: DoubleValidator { locale: qsTr("en_US") }

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.temperature0;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.temperature0 = parseFloat(text);
                                    }
                                }
                            }

                            // Temperature E
                            Label {
                                Layout.margins: 2.5
                                text: qsTr("Temperature E")
                            }
                            CTextField {
                                Layout.fillWidth: true

                                height: 40
                                text: qsTr("293")
                                validator: DoubleValidator { locale: qsTr("en_US") }

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.temperatureE;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.temperatureE = parseFloat(text);
                                    }
                                }
                            }

                            // Measure Time Traces
                            CheckBox {
                                Layout.columnSpan: 2
                                Layout.fillWidth: true
                                Layout.fillHeight: true

                                id: chkMeasureTimeTraces
                                checked: true
                                text: qsTr("Measure time traces")

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        checked = noiseFETSettingsModel.measureTimeTraces;
                                    }
                                }
                                onCheckedChanged: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.measureTimeTraces = checked;
                                    }
                                }
                            }
                            Label {
                                Layout.margins: 2.5
                                enabled: chkMeasureTimeTraces.checked
                                text: qsTr("TT Sampling frequency")
                            }
                            CTextField {
                                Layout.fillWidth: true

                                enabled: chkMeasureTimeTraces.checked
                                height: 40
                                text: qsTr("262144")
                                validator: IntValidator { locale: qsTr("en_US") }

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.timeTraceFrequency;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.timeTraceFrequency = parseInt(text);
                                    }
                                }
                            }

                            // Save to file controls
                            Button {
                                Layout.fillWidth: true
                                Layout.fillHeight: true

                                text: qsTr("...")
                            }
                            CTextField {
                                Layout.fillWidth: true
                                Layout.fillHeight: true
                                horizontalAlignment: Qt.AlignLeft
                                placeholderText: qsTr("Save file name")

                                Component.onCompleted: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        text = noiseFETSettingsModel.dataFileName;
                                    }
                                }
                                onEditingFinished: {
                                    if (typeof noiseFETSettingsModel !== "undefined") {
                                        noiseFETSettingsModel.dataFileName = text;
                                    }
                                }
                            }
                        }
                    }
                }

                Item {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.maximumHeight: 40

                    RowLayout { 
                        anchors.fill: parent
                        Button {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            text: qsTr("Start")
                        }
                        Button {
                            Layout.fillWidth: true
                            Layout.fillHeight: true
                            text: qsTr("Stop")
                        }
                    }
                }
            }
        }
    }

    function setVoltageArrayString(start, stop, step) {
        var strStart = start.toString();
        var strStop = stop.toString();
        var strStep = step.toString();

        var precision = strStep.length - strStep.indexOf(".") - 1;

        var floatStart = parseFloat(start);
        var floatStop = parseFloat(stop);
        var floatStep = parseFloat(step);

        var nElements = parseInt(Math.abs((floatStop - floatStart) / floatStep)) + 1;

        var res = "[ ";
        for (var i = 0; i < nElements - 1; i++) {
            res += (floatStart + i * floatStep).toFixed(precision) + ", ";
        }
        res += (start + step * (nElements - 1)).toFixed(precision) + " ]";

        return res;
    }

    function setGateVoltageArray(start, stop, step) {
        var res = setVoltageArrayString(start, stop, step);

        gateVoltageValues.text = res;
        gateVoltageValues.arrayElements = JSON.parse(res);
    }

    function setDrainVoltageArray(start, stop, step) {
        var res = setVoltageArrayString(start, stop, step);

        drainVoltageValues.text = res;
        drainVoltageValues.arrayElements = JSON.parse(res);
    }
}
