#-------------------------------------------------
#
# Project created by QtCreator 2019-04-28T18:26:23
#
#-------------------------------------------------

QT       -= gui

QT += network

TARGET = weather
TEMPLATE = lib

DEFINES += WEATHERLIB_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commons/converter/temperatureconverter.cpp \
    controller/settingscontroller.cpp \
    controller/weathercontroller.cpp \
    model/settingsmodel.cpp \
    model/weathermodel.cpp \
    repository/settings/settingsrepository.cpp \
    repository/openweather/openweathercurrentresponse.cpp \
    repository/openweather/openweatherrepository.cpp \
    repository/openweather/openweatherweatherresponse.cpp \
    repository/weatherrepository.cpp \
    repository/weatherrepositoryfactory.cpp \
    service/settingsservice.cpp \
    service/weatherservice.cpp

HEADERS += \
    commons/converter/temperatureconverter.h \
    commons/domain/temperatureunitenum.h \
    controller/settingscontroller.h \
    controller/weathercontroller.h \
    model/settingsmodel.h \
    model/weathermodel.h \
    repository/settings/settingsrepository.h \
    repository/openweather/openweathercurrentresponse.h \
    repository/openweather/openweatherrepository.h \
    repository/openweather/openweatherweatherresponse.h \
    repository/weatherrepositoryfactory.h \
    service/settingsservice.h \
    service/weatherservice.h \
    weather-lib_global.h \
    repository/weatherrepository.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
