#ifndef WEATHERCONTROLLER_H
#define WEATHERCONTROLLER_H

#include <QObject>

#include "service/weatherservice.h"

WEATHER_LIB_NAMESPACE_BEGIN

class WeatherController : public QObject {
  Q_OBJECT
public:
  explicit WeatherController(QObject *parent = Q_NULLPTR);

public slots:
  void current();
  void forecast();

private:
  WeatherService _weatherService;

signals:
  void currentWeather(WeatherModel *weather);
  void forecasts(QList<QObject *> weatherList);
};

WEATHER_LIB_NAMESPACE_END

#endif // WEATHERCONTROLLER_H
