import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    id: root
    width: 150
    height: 30

    property alias input: input
    property alias placeholderText: input.placeholderText
    property alias text: input.text
    property alias validator: input.validator

    TextField {
        id: input
        anchors.fill: parent
        focus: true
        selectByMouse: true
        autoScroll: true

        background: Rectangle {
            anchors.fill: parent
            color: "lightsteelblue"
            border.color: "gray"
        }
    }
}
