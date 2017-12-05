import QtQuick 2.2

import QtQuick.Controls 2.2
import QtQuick.Controls.Styles 1.4

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
            border.color: "gray"
        }
    }
}
