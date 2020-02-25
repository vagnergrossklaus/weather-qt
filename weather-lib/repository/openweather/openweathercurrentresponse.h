#ifndef OPENWEATHERCURRENTRESPONSE_H
#define OPENWEATHERCURRENTRESPONSE_H

#include "weather-lib_global.h"

WEATHER_LIB_NAMESPACE_BEGIN

class OpenWeatherCurrentResponse {
public:
  OpenWeatherCurrentResponse();

  void fromJson(const QByteArray &data);

private:
};

WEATHER_LIB_NAMESPACE_END

#endif // OPENWEATHERCURRENTRESPONSE_H
