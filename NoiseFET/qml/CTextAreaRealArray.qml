import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    width: 150
    height: 60

    property alias text: input.text
    property alias input: input

    property variant arrayElements: [0.0]

    function parseArrElementsFromText (inputText) {
        if (inputText.charAt(inputText.length - 1) === ',') {
            inputText = inputText.substring(0, inputText.length -1);
        }
        arrayElements = JSON.parse("[" + inputText + "]")
    }

    function validateTextChanged(inputChar) {

    }

    ScrollView {
        id: view
        anchors.fill: parent

        TextArea {
            id: input
            focus: true
            selectByMouse: true
            text: qsTr("[ 0.0 ]")
            wrapMode: TextEdit.Wrap

            background: Rectangle {
                color: "lightsteelblue"
                border.color: "gray"
            }

            onEditingFinished: parseArrElementsFromText(text)
        }
    }
}
