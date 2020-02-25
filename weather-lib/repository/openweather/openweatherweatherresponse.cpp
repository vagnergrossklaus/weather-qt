#include "openweatherweatherresponse.h"

WEATHER_LIB_NAMESPACE_BEGIN

OpenWeatherWeatherResponse::OpenWeatherWeatherResponse() {}

QString OpenWeatherWeatherResponse::main() const { return _main; }

void OpenWeatherWeatherResponse::setMain(const QString &main) { _main = main; }

QString OpenWeatherWeatherResponse::description() const { return _description; }

void OpenWeatherWeatherResponse::setDescription(const QString &description) {
  _description = description;
}

QString OpenWeatherWeatherResponse::icon() const { return _icon; }

void OpenWeatherWeatherResponse::setIcon(const QString &icon) { _icon = icon; }

WEATHER_LIB_NAMESPACE_END
