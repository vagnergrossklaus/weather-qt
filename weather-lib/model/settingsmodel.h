#ifndef SETTINGSMODEL_H
#define SETTINGSMODEL_H

#include "weather-lib_global.h"

#include <QLocale>
#include <QString>

#include "commons/domain/temperatureunitenum.h"

WEATHER_LIB_NAMESPACE_BEGIN

class SettingsModel {
public:
  SettingsModel();

  QString apiKey() const;
  void setApiKey(const QString &apiKey);

  QString city() const;
  void setCity(const QString &city);

  QString country() const;
  void setCountry(const QString &country);

  QLocale::MeasurementSystem measurementSystem() const;
  void
  setMeasurementSystem(const QLocale::MeasurementSystem &measurementSystem);

  int forecastCount() const;
  void setForecastCount(int forecastCount);

private:
  int _forecastCount = 0;
  QString _apiKey = "";
  QString _city = "";
  QString _country = "";
  QLocale::MeasurementSystem _measurementSystem = QLocale().measurementSystem();
};

WEATHER_LIB_NAMESPACE_END

#endif // SETTINGSMODEL_H
