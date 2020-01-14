import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    //title: qsTr("Hello World")

    MainForm {
        Button {
            x: 100;
            y: 120;
        }
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            Qt.quit();
//        }
    }
}
