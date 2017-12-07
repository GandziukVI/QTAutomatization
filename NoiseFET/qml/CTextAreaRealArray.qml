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

        var strStep = stepVal.toString();
        var dataPrecision = strStep.length - strStep.indexOf(".") - 1;
        var dataDiviedr = Math.pow(10, dataPrecision);

        var tempData = new Array(nElements);

        for (var i = 0; i < nElements; i++) {
            tempData[i] = Math.round((floatStart + i * floatStep) * dataDiviedr) / dataDiviedr;
        }

        text = "[ ";
        text += tempData.join(", ");
        text += " ]";
    }
}
