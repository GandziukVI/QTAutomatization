import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Window 2.2

import QtQuick.Layouts 1.3

Window {
    id: root
    flags: Qt.Window | Qt.WindowTitleHint | Qt.WindowSystemMenuHint | Qt.WindowCloseButtonHint
    modality: Qt.WindowModal
    title: qsTr("Channel Parameters")

    width: 640
    height: 300

    Item {
        anchors.fill: parent
        GridLayout {
            anchors.fill: parent
            anchors.margins: 10
            columns: 2

            // Channel number 1-4

            Text {
                text: qsTr("Channel number")
            }

            ComboBox {
                Layout.fillWidth: true

                property variant chNumberModel: ListModel {
                    ListElement { text: qsTr("Channel 01") }
                    ListElement { text: qsTr("Channel 02") }
                    ListElement { text: qsTr("Channel 03") }
                    ListElement { text: qsTr("Channel 04") }
                }

                model: chNumberModel
            }

            Text {
                text: qsTr("Channel mode")
            }

            ComboBox {
                Layout.fillWidth: true

                property variant chChannelModel: ListModel {
                    ListElement { text: qsTr("AC Mode") }
                    ListElement { text: qsTr("DC Mode") }
                }

                model: chChannelModel
            }

            // Filter params: filter gain

            Text {
                text: qsTr("Filter gain")
            }

            ComboBox {
                Layout.fillWidth: true

                property variant chFilterGain: ListModel {
                    ListElement { text: qsTr("Gain 1") }
                    ListElement { text: qsTr("Gain 2") }
                    ListElement { text: qsTr("Gain 3") }
                    ListElement { text: qsTr("Gain 4") }
                    ListElement { text: qsTr("Gain 5") }
                    ListElement { text: qsTr("Gain 6") }
                    ListElement { text: qsTr("Gain 7") }
                    ListElement { text: qsTr("Gain 8") }
                    ListElement { text: qsTr("Gain 9") }
                    ListElement { text: qsTr("Gain 10") }
                    ListElement { text: qsTr("Gain 11") }
                    ListElement { text: qsTr("Gain 12") }
                    ListElement { text: qsTr("Gain 13") }
                    ListElement { text: qsTr("Gain 14") }
                    ListElement { text: qsTr("Gain 15") }
                    ListElement { text: qsTr("Gain 16") }
                }

                model: chFilterGain
            }

            // Filter params: cut-off frequency

            Text {
                text: qsTr("Filter cut-off freq.")
            }

            ComboBox {
                Layout.fillWidth: true

                property variant chFilterFrequency: ListModel {
                    ListElement { text: qsTr("Freq 0 kHz") }
                    ListElement { text: qsTr("Freq 10 kHz") }
                    ListElement { text: qsTr("Freq 20 kHz") }
                    ListElement { text: qsTr("Freq 30 kHz") }
                    ListElement { text: qsTr("Freq 40 kHz") }
                    ListElement { text: qsTr("Freq 50 kHz") }
                    ListElement { text: qsTr("Freq 60 kHz") }
                    ListElement { text: qsTr("Freq 70 kHz") }
                    ListElement { text: qsTr("Freq 80 kHz") }
                    ListElement { text: qsTr("Freq 90 kHz") }
                    ListElement { text: qsTr("Freq 100 kHz") }
                    ListElement { text: qsTr("Freq 110 kHz") }
                    ListElement { text: qsTr("Freq 120 kHz") }
                    ListElement { text: qsTr("Freq 130 kHz") }
                    ListElement { text: qsTr("Freq 140 kHz") }
                    ListElement { text: qsTr("Freq 150 kHz") }
                }

                model: chFilterFrequency
            }

            // PGA gain

            Text {
                text: qsTr("PGA gain")
            }

            ComboBox {
                Layout.fillWidth: true

                property variant chPGAGain: ListModel {
                    ListElement { text: qsTr("Gain 1") }
                    ListElement { text: qsTr("Gain 10") }
                    ListElement { text: qsTr("Gain 100") }
                }

                model: chPGAGain
            }

            Button {
                Layout.columnSpan: 2
                Layout.fillWidth: true

                text: qsTr("Set params")

                onClicked: {
                    root.close();
                }
            }
        }

        Keys.onPressed: {
            if (event.key === Qt.Key_Return || event.key === Qt.Key_Enter) {
                root.close();
            }
            else if (event.key === Qt.Key_Escape) {
                root.close();
            }
        }
    }
}
