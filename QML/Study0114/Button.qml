import QtQuick 2.0

Rectangle {
    id: button
    width: 100
    height: 30
    color: "white"
    border.color: "slategrey"
//    Text {
//        anchors.centerIn: parent
//        text: "start"
//    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            status.text = "clicked..."
        }
    }
    Text {
        id: status
        width:100
        height:30
        text:"waiting..."
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
}
