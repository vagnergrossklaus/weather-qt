#include "weatherrepository.h"

WEATHER_LIB_NAMESPACE_BEGIN

WeatherRepository::WeatherRepository(const QString &apiKey, QObject *parent)
    : QObject(parent), _apiKey(apiKey) {}

QString WeatherRepository::apiKey() const { return _apiKey; }

WEATHER_LIB_NAMESPACE_END
