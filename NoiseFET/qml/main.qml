import QtQuick 2.6
import QtCharts 2.2
import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4
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

            width: parent.width - noiseFETSettings.width
            height: parent.height

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.margins: 5

            LineSeries {
                id: nosieFETLineGraph

                axisX: LogValueAxis {
                    id: noiseFETFrequencyAxis
                    min: 0.5
                    max: 500000
                    titleText: qsTr("Frequency")
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

        GridLayout {
            id: noiseFETSettings
            anchors.top: parent.top

            columns: 2

            // Agilent U2542A resource name
            Label {
                Layout.margins: 2.5
                text: qsTr("Agilent U2542A res.")
            }
            CTextArea {
                Layout.margins: 2.5
                width: 150
                text: qsTr("USB0::2391::5912::TW54334510::INSTR")
            }

            // Set of gate voltages
            Label {
                Layout.margins: 2.5
                text: qsTr("Gate Voltages")
            }
            CTextAreaRealArray {
                id: gateVoltageValues
                Layout.margins: 2.5
                width: 150
                text: qsTr("[0.0 ]")
            }
            Button {
                id: cmdSetVGRange

                Layout.columnSpan: 2
                Layout.fillWidth: true

                text: qsTr("<p>Set V<sub>G</sub> range</p>")

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
                id: drainVoltageValues
                Layout.margins: 2.5
                width: 150
                text: qsTr("[0.0 ]")
            }
            Button {
                id: cmdSetVDSRange

                Layout.columnSpan: 2
                Layout.fillWidth: true

                text: qsTr("<p>Set V<sub>DS</sub> range</p>")

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
                Layout.margins: 2.5
                height: 40
                text: qsTr("0.2")
                validator: DoubleValidator { locale: qsTr("en_US") }
                units: qsTr("V")
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

        var nElements = parseInt(Math.abs((floatStop - floatStart) / floatStep));

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
