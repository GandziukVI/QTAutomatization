import QtQuick 2.0
import QtQuick.Controls 2.2

Rectangle {
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
        autoScroll: true
        focus: true
        horizontalAlignment: TextField.AlignRight
        rightPadding: 10
        selectByMouse: true

        background: Rectangle {
            anchors.fill: parent
            color: "lightsteelblue"
            border.color: "gray"
        }
    }
}
