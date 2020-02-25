#include "weatherservice.h"

#include "commons/converter/temperatureconverter.h"
#include "model/settingsmodel.h"
#include "repository/weatherrepositoryfactory.h"

WEATHER_LIB_NAMESPACE_BEGIN

WeatherService::WeatherService(SettingsModel *settings)
    : _settings(settings),
      _weatherRepository(WeatherRepositoryFactory::build(settings->apiKey())) {}

WeatherModel *WeatherService::current() {
  WeatherModel *weather = _weatherRepository->current(
      _settings->city(), _settings->country(), _settings->measurementSystem());

  normalize({weather});

  return weather;
}

QVector<WeatherModel *> WeatherService::forecast() {
  return _weatherRepository->forecast(_settings->city(), _settings->country(),
                                      _settings->measurementSystem());
}

void WeatherService::normalize(QVector<WeatherModel *> /*weathers*/) {
  //  for (auto weather : weathers) {
  //    weather->setCurrentTemperature(TemperatureConverter::convert(
  //        weather->currentTemperature(), weather->temperatureUnit(),
  //        _settings->temperatureUnit()));
  //    weather->setMinimumTemperature(TemperatureConverter::convert(
  //        weather->minimumTemperature(), weather->temperatureUnit(),
  //        _settings->temperatureUnit()));
  //    weather->setMaximumTemperature(TemperatureConverter::convert(
  //        weather->maximumTemperature(), weather->temperatureUnit(),
  //        _settings->temperatureUnit()));
  //    weather->setTemperatureUnit(_settings->temperatureUnit());
  //  }
}

WEATHER_LIB_NAMESPACE_END
