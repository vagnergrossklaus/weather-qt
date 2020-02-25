import QtQuick 2.0

Item {

    height: 25

    Timer {
        interval: 500; running: true; repeat: true
        onTriggered: time.text = Qt.formatDateTime(new Date(), "dd/MM/yyyy hh:mm")
    }

    Text {
        id: platform
        text: Qt.platform.os.toUpperCase()
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 5
    }

    Text {
        id: time
        text: qsTr("00/00/0000 00:00")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignRight
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        anchors.rightMargin: 5
    }

}
