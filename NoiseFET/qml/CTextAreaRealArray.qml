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
                root.editingFinished
            }
        }
    }

    function setData(startVal, stopVal, stepVal) {
        var floatStart = parseFloat(startVal);
        var floatStop = parseFloat(stopVal);
        var floatStep = parseFloat(stepVal);

        var nElements = parseInt(Math.abs((floatStop - floatStart) / floatStep)) + 1;

        arrayElements = [];
        arrayElements = new Array(nElements);

        for (var i = 0; i < arrayElements.length; i++) {
            arrayElements[i] = floatStart + i * floatStep;
        }

        var strStep = stepVal.toString();
        var precision = strStep.length - strStep.indexOf(".") - 1;

        text = "[ ";
        text += arrayElements.join(", ") + " ]";
    }
}
