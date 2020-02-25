#include "weathermodel.h"

WEATHER_LIB_NAMESPACE_BEGIN

WeatherModel::WeatherModel(QObject *parent) : QObject(parent) {}

QDate WeatherModel::date() const { return _date; }

void WeatherModel::setDate(const QDate &date) {
  _date = date;
  emit dateChanged();
}

double WeatherModel::currentTemperature() const { return _currentTemperature; }

void WeatherModel::setCurrentTemperature(double currentTemperature) {
  _currentTemperature = currentTemperature;
  emit currentTemperatureChanged();
}

double WeatherModel::minimumTemperature() const { return _minimumTemperature; }

void WeatherModel::setMinimumTemperature(double minimumTemperature) {
  _minimumTemperature = minimumTemperature;
  emit minimumTemperatureChanged();
}

double WeatherModel::maximumTemperature() const { return _maximumTemperature; }

void WeatherModel::setMaximumTemperature(double maximumTemperature) {
  _maximumTemperature = maximumTemperature;
  emit maximumTemperatureChanged();
}

TemperatureUnitEnum WeatherModel::temperatureUnit() const {
  return _temperatureUnit;
}

void WeatherModel::setTemperatureUnit(
    const TemperatureUnitEnum &temperatureUnit) {
  _temperatureUnit = temperatureUnit;
  emit temperatureUnitChanged();
}

WeatherModel *WeatherModel::clone(WeatherModel *weather) {
  WeatherModel *newWeather = new WeatherModel();
  newWeather->setDate(weather->date());
  newWeather->setCurrentTemperature(weather->currentTemperature());
  newWeather->setMinimumTemperature(weather->minimumTemperature());
  newWeather->setMaximumTemperature(weather->maximumTemperature());
  return newWeather;
}

QList<WeatherModel *> WeatherModel::clone(QList<WeatherModel *> weatherList) {
  QList<WeatherModel *> newWeatherList = {};
  for (auto weather : weatherList) {
    newWeatherList.append(clone(weather));
  }
  return newWeatherList;
}

QList<QObject *> WeatherModel::toObjectList(QList<WeatherModel *> weatherList) {
  QList<QObject *> objects = {};
  for (auto weather : weatherList) {
    objects.append(weather);
  }
  return objects;
}

WEATHER_LIB_NAMESPACE_END
