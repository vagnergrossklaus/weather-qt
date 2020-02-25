#ifndef WEATHERREPOSITORY_H
#define WEATHERREPOSITORY_H

#include "model/weathermodel.h"

#include <QLocale>
#include <QObject>
#include <QVector>

WEATHER_LIB_NAMESPACE_BEGIN

class WeatherRepository : public QObject {
  Q_OBJECT
public:
  WeatherRepository(const QString &apiKey, QObject *parent = Q_NULLPTR);
  virtual WeatherModel *
  current(const QString &city, const QString &country,
          const QLocale::MeasurementSystem &measurementUnitSystem) = 0;
  virtual QVector<WeatherModel *>
  forecast(const QString &city, const QString &country,
           const QLocale::MeasurementSystem &measurementUnitSystem) = 0;

protected:
  QString apiKey() const;

private:
  QString _apiKey = "";
};

WEATHER_LIB_NAMESPACE_END

#endif // WEATHERREPOSITORY_H
