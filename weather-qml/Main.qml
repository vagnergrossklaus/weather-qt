import QtQuick 2.7

import WeatherController 1.0;

MainForm {

    id: form

    Timer {
        interval: 50000; running: true; repeat: true
        onTriggered: {
            control.forecast()
            control.current()
        }
    }

    WeatherController{
        id: control

        onCurrentWeather: function(weather){
            form.current.weather = weather
        }

        onForecasts: function (list) {
            form.repeater.model = list
        }

    }

    Component.onCompleted: {
        control.forecast()
        control.current()
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
