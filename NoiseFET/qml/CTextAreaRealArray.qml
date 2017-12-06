import QtQuick 2.2
import QtQuick.Controls 2.2

Item {
    id: root

    width: 150
    height: 60

    property alias text: input.text
    property alias input: input

    property var arrayElements: [0.0]

    signal editingFinished()

    function parseArrElementsFromText (inputText) {
        arrayElements = JSON.parse(inputText)
    }

    ScrollView {
        id: view
        anchors.fill: parent

        TextArea {
            id: input
            clip: true
            focus: true
            horizontalAlignment: TextArea.AlignRight
            rightPadding: 10
            selectByMouse: true
            text: qsTr("[ 0.0 ]")
            wrapMode: TextEdit.Wrap

            background: Rectangle {
                border.color: "gray"
            }

            onEditingFinished: {
                parseArrElementsFromText(text)
                root.editingFinished
            }
        }
    }

    Component.onCompleted: {
        parseArrElementsFromText(text)
    }

    onArrayElementsChanged: {
        var arrLen = arrayElements.length;

        text = "[ ";

        text += arrayElements.join(", ")

        text += " ]";
    }
}
