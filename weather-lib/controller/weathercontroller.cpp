#include "weathercontroller.h"

#include "settingscontroller.h"

WEATHER_LIB_NAMESPACE_BEGIN

WeatherController::WeatherController(QObject *parent)
    : QObject(parent), _weatherService(SettingsController().find()) {}

void WeatherController::current() {
  emit currentWeather(_weatherService.current());
}

void WeatherController::forecast() {
  emit forecasts(
      WeatherModel::toObjectList(_weatherService.forecast().toList()));
}

WEATHER_LIB_NAMESPACE_END
