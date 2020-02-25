#ifndef WEATHERSERVICE_H
#define WEATHERSERVICE_H

#include "repository/weatherrepository.h"

WEATHER_LIB_NAMESPACE_BEGIN

class SettingsModel;
class WeatherService {
public:
  WeatherService(SettingsModel *settings);

  WeatherModel *current();
  QVector<WeatherModel *> forecast();

private:
  SettingsModel *_settings;
  WeatherRepository *_weatherRepository;

  void normalize(QVector<WeatherModel *> weathers);
};

WEATHER_LIB_NAMESPACE_END

#endif // WEATHERSERVICE_H
