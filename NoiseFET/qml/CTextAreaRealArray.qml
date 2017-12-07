import QtQuick 2.2
import QtQuick.Controls 2.2

import "../js/CTextAreaArray.js" as CTextRealArrayFunctions

Item {
    id: root

    width: 150
    height: 60

    property alias text: input.text
    property alias input: input

    property var arrayElements: new Array(1)

    signal editingFinished()
    signal setData(real dataStart, real dataStop, real dataStep)

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

    onEditingFinished: {
        arrayElements = JSON.parse(text);
    }

    Component.onCompleted: {
        setData.connect(function(dataStart, dataStop, dataStep) {
            arrayElements = CTextRealArrayFunctions.setData(dataStart, dataStop, dataStep);
            input.text = "[ ";
            input.text += arrayElements.join(", ") + " ]";
        });
    }
    Component.onDestruction: {
        arrayElements = null;
    }
}
