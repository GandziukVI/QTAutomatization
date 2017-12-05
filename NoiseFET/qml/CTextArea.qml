import QtQuick 2.2
import QtQuick.Controls 2.2

Item {
    width: 150
    height: 60

    property alias text: input.text
    property alias input: input

    ScrollView {
        id: view
        anchors.fill: parent

        TextArea {
            id: input
            focus: true
            horizontalAlignment: TextArea.AlignRight
            rightPadding: 10
            selectByMouse: true
            wrapMode: TextEdit.Wrap

            background: Rectangle {
                border.color: "gray"
            }
        }
    }
}

