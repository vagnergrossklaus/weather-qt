#include "openweathercurrentresponse.h"

#include <QJsonDocument>

WEATHER_LIB_NAMESPACE_BEGIN

OpenWeatherCurrentResponse::OpenWeatherCurrentResponse() {}

void OpenWeatherCurrentResponse::fromJson(const QByteArray &data) {
  QJsonDocument json = QJsonDocument::fromJson(data);
}

WEATHER_LIB_NAMESPACE_END
