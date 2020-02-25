#include "weatherrepositoryfactory.h"

#include "openweather/openweatherrepository.h"

WEATHER_LIB_NAMESPACE_BEGIN

WeatherRepository *WeatherRepositoryFactory::build(const QString &apikey) {
  return new OpenWeatherRepository(apikey);
}

WEATHER_LIB_NAMESPACE_END
