#ifndef WEATHERMODEL_H
#define WEATHERMODEL_H

#include "weather-lib_global.h"

#include <QDate>
#include <QMap>
#include <QObject>

#include "commons/domain/temperatureunitenum.h"

WEATHER_LIB_NAMESPACE_BEGIN

class WeatherModel : public QObject {
  Q_OBJECT
  Q_PROPERTY(QDate date READ date NOTIFY dateChanged)
  Q_PROPERTY(double currentTemperature READ currentTemperature NOTIFY
                 currentTemperatureChanged)
  Q_PROPERTY(double minimumTemperature READ minimumTemperature NOTIFY
                 minimumTemperatureChanged)
  Q_PROPERTY(double maximumTemperature READ maximumTemperature NOTIFY
                 maximumTemperatureChanged)
  //  Q_PROPERTY(TemperatureUnitEnum temperatureUnit READ temperatureUnit NOTIFY
  //                 temperatureUnitChanged)
public:
  WeatherModel(QObject *parent = Q_NULLPTR);

  QDate date() const;
  void setDate(const QDate &date);

  double currentTemperature() const;
  void setCurrentTemperature(double currentTemperature);

  double minimumTemperature() const;
  void setMinimumTemperature(double minimumTemperature);

  double maximumTemperature() const;
  void setMaximumTemperature(double maximumTemperature);

  TemperatureUnitEnum temperatureUnit() const;
  void setTemperatureUnit(const TemperatureUnitEnum &temperatureUnit);

  static WeatherModel *clone(WeatherModel *weather);
  static QList<WeatherModel *> clone(QList<WeatherModel *> weatherList);
  static QList<QObject *> toObjectList(QList<WeatherModel *> weatherList);

private:
  QDate _date = QDate();
  double _currentTemperature = 0.0;
  double _minimumTemperature = 0.0;
  double _maximumTemperature = 0.0;
  TemperatureUnitEnum _temperatureUnit = TemperatureUnitEnum::NONE;

signals:
  void dateChanged();
  void currentTemperatureChanged();
  void minimumTemperatureChanged();
  void maximumTemperatureChanged();
  void temperatureUnitChanged();
};

WEATHER_LIB_NAMESPACE_END

#endif // WEATHERMODEL_H
