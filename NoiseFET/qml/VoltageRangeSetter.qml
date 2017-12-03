import QtQuick 2.9
import QtQuick.Window 2.3
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQml 2.2

Window {
    id: root
    flags: Qt.Window | Qt.WindowTitleHint | Qt.WindowSystemMenuHint | Qt.WindowCloseButtonHint
    modality: Qt.WindowModal
    title: qsTr("Range Setter")

    width: 360
    height: 200

    property double startValue: 0.0
    property double stopValue: 1.0
    property double nPoints: 101

    function setPropertyData() {
        startValue = parseFloat(startValField.text);
        stopValue = parseFloat(stopValField.text);
        nPoints = parseInt(nPointsValField.text);
    }

    Item {
        anchors.fill: parent
        GridLayout {
            anchors.fill: parent
            anchors.margins: 10
            columns: 2

            Label {
                text: qsTr("Start Value")
            }
            CTextField {
                id: startValField
                width: 250
                text: qsTr("0.0")
                validator: DoubleValidator { locale: qsTr("en_US") }
                placeholderText: qsTr("Start Value")
            }

            Label {
                text: qsTr("Stop Value")
            }
            CTextField {
                id: stopValField
                width : 250
                text: qsTr("1.0")
                validator: DoubleValidator { locale: qsTr("en_US") }
                placeholderText: qsTr("Stop Value")
            }

            Label {
                text: qsTr("nPoints")
            }
            CTextField {
                id: nPointsValField
                width:250
                text: qsTr("101")
                validator: IntValidator { locale: qsTr("en_US") }
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
                    root.close();
                }
            }

            Keys.onPressed: {
                if (event.key === Qt.Key_Return) {
                    setPropertyData();
                    root.close();
                }
                else if (event.key === Qt.Key_Escape)
                    root.close();
            }
        }
    }
}
