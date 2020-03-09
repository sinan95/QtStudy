import QtQuick 2.5

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        TextEdit {
            id: textEdit1
            x: 267
            y: 72
            width: 80
            height: 20
            text: "test\n"
            font.pixelSize: 12
        }

        TextInput {
            id: textInput1
            x: 267
            y: 16
            width: 80
            height: 20
            text: "test"
            font.pixelSize: 12
        }
    }

    Text {
        anchors.centerIn: parent
        text: "Hello World"
    }
}
