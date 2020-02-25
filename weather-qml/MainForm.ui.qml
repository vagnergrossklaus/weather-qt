import QtQuick 2.7
import QtQuick.Controls 2.0

Item {
    id: content
    width: 400
    height: 400
    anchors.fill: parent

    property alias current: current
    property alias repeater: repeater
    property alias statusBar: statusBar

    StatusBar {
        id: statusBar
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
    }

    Condition {
        id: current
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: statusBar.bottom
        anchors.topMargin: 0
    }

    Row {

        anchors.right: parent.right
        anchors.rightMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        anchors.top: current.bottom
        anchors.topMargin: 10

        padding: 10
        spacing: 10

        Repeater {
            id: repeater
            model: content.model
            Condition {
                height: 100
                weather: modelData
            }
        }
    }
}

/*##^##
Designer {
    D{i:1;anchors_x:148;anchors_y:8}
}
##^##*/

