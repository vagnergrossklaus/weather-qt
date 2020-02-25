#ifndef WEATHERREPOSITORYFACTORY_H
#define WEATHERREPOSITORYFACTORY_H

#include "weatherrepository.h"

WEATHER_LIB_NAMESPACE_BEGIN

class WeatherRepositoryFactory {
public:
    static WeatherRepository* build(const QString &apikey);
private:
    WeatherRepositoryFactory() = default;
};

WEATHER_LIB_NAMESPACE_END

#endif // WEATHERREPOSITORYFACTORY_H
