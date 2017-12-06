import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

import QtQuick.Layouts 1.3

Window {
    id: root
    flags: Qt.Window | Qt.WindowTitleHint | Qt.WindowSystemMenuHint | Qt.WindowCloseButtonHint
    modality: Qt.WindowModal
    title: qsTr("Range Setter")

    width: 360
    height: 200

    property string startValue: "0.0"
    property string stopValue: "1.0"
    property string stepValue: "0.05"

    signal dataChanged(real start, real stop, real step)

    function setPropertyData() {
        startValue = startValField.realValue.toString();
        stopValue = stopValField.realValue.toString();
        stepValue = stepValField.realValue.toString();
    }

    Item {
        anchors.fill: parent
        GridLayout {
            anchors.fill: parent
            anchors.margins: 10
            columns: 2

            Label {
                id: startValLabel
                text: qsTr("Start Value")
            }
            CExtendedNumberInput {
                id: startValField

                anchors.leftMargin: 5

                height: 40
                Layout.fillWidth: true

                text: qsTr("0.0")
                validator: DoubleValidator { locale: qsTr("en_US") }
                placeholderText: qsTr("Start Value")
            }

            Label {
                id: stopValLabel
                text: qsTr("Stop Value")
            }
            CExtendedNumberInput {
                id: stopValField

                anchors.leftMargin: 5

                height: 40
                Layout.fillWidth: true

                text: qsTr("1.0")
                validator: DoubleValidator { locale: qsTr("en_US") }
                placeholderText: qsTr("Stop Value")
            }

            Label {
                id: stepValLabel
                text: qsTr("Step Value")
            }
            CExtendedNumberInput {
                id: stepValField

                anchors.leftMargin: 5

                height: 40
                Layout.fillWidth: true

                text: qsTr("0.05")
                validator: DoubleValidator { locale: qsTr("en_US") }
                placeholderText: qsTr("Number of points")
            }

            Button {
                id: setRangeButton
                Layout.columnSpan: 2
                anchors.left: parent.left
                anchors.right: parent.right
                text: qsTr("Set range")
                onClicked: {
                    setPropertyData();
                    dataChanged(startValue, stopValue, stepValue);
                    root.close();
                }
            }

            Keys.onPressed: {
                if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                    setPropertyData();
                    dataChanged(startValue, stopValue, stepValue);
                    root.close();
                }
                else if (event.key === Qt.Key_Escape) {
                    root.close();
                }
            }
        }
    }
}
