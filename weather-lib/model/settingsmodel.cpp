#include "settingsmodel.h"

WEATHER_LIB_NAMESPACE_BEGIN

SettingsModel::SettingsModel() {}

QString SettingsModel::apiKey() const { return _apiKey; }

void SettingsModel::setApiKey(const QString &apiKey) { _apiKey = apiKey; }

QString SettingsModel::city() const { return _city; }

void SettingsModel::setCity(const QString &city) {
  _city = QString(city).remove("[^a-zA-Z\\d\\s]");
}

QString SettingsModel::country() const { return _country; }

void SettingsModel::setCountry(const QString &country) {
  _country = QString(country).remove("[^a-zA-Z\\d\\s]");
}

QLocale::MeasurementSystem SettingsModel::measurementSystem() const {
  return _measurementSystem;
}

void SettingsModel::setMeasurementSystem(
    const QLocale::MeasurementSystem &measurementSystem) {
  _measurementSystem = measurementSystem;
}

int SettingsModel::forecastCount() const { return _forecastCount; }

void SettingsModel::setForecastCount(int forecastCount) {
  _forecastCount = forecastCount;
}

WEATHER_LIB_NAMESPACE_END
