import QtQuick 2.0

Item {

    id: condition
    width: 100
    height: 100

    property var weather: undefined
    property alias date: date
    property alias minTemperature: minTemperature
    property alias maxTemperature: maxTemperature

    Text {
        id: date
        text: Qt.formatDate(weather.date, "dddd, dd/MM")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
    }

    Text {
        id: minTemperature
        height: 50
        text: "Min " + weather.minimumTemperature + "º"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: date.bottom
        anchors.topMargin: 0
        font.pixelSize: 12
    }

    Text {
        id: currentTemperature
        height: 50
        text: weather.currentTemperature + "º"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: minTemperature.bottom
        anchors.topMargin: 0
        font.pixelSize: 16
    }

    Text {
        id: maxTemperature
        y: 306
        height: 50
        text: "Max " + weather.maximumTemperature + "º"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.top: currentTemperature.bottom
        anchors.topMargin: 0
        font.pixelSize: 12
    }

}
