#include "settingsrepository.h"

#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <QLocale>
#include <QSettings>

#include <commons/domain/temperatureunitenum.h>
#include <model/settingsmodel.h>

WEATHER_LIB_NAMESPACE_BEGIN

SettingsRepository::SettingsRepository() {
  _filePath = QCoreApplication::applicationDirPath() + QDir::separator() +
              SettingsRepository::FILE_NAME;
  qDebug() << "SettingsRepository::SettingsRepository [FILE_PATH]" << _filePath
           << "[EXISTS]" << QFile(_filePath).exists();
}

void SettingsRepository::insert(SettingsModel *settings) {}

SettingsModel *SettingsRepository::find() {

  SettingsModel *settings = new SettingsModel();

  QSettings file(_filePath, QSettings::IniFormat);

  settings->setApiKey(
      file.value(SettingsRepository::GENERAL_API_KEY).toString());
  settings->setForecastCount(
      file.value(SettingsRepository::FORECAST_COUNT).toInt());

  settings->setCity(file.value(SettingsRepository::LOCATION_CITY).toString());
  settings->setCountry(
      file.value(SettingsRepository::LOCATION_COUNTRY).toString());
  settings->setMeasurementSystem(QLocale::MeasurementSystem(
      file.value(SettingsRepository::LOCATION_MEASUREMENT_SYSTEM,
                 QLocale().measurementSystem())
          .toInt()));

  return settings;
}

WEATHER_LIB_NAMESPACE_END
