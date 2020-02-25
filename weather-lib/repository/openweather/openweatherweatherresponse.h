#ifndef OPENWEATHERWEATHERRESPONSE_H
#define OPENWEATHERWEATHERRESPONSE_H

#include "repository/weatherrepository.h"

WEATHER_LIB_NAMESPACE_BEGIN

class OpenWeatherWeatherResponse {
public:
  OpenWeatherWeatherResponse();

  QString main() const;
  void setMain(const QString &main);

  QString description() const;
  void setDescription(const QString &description);

  QString icon() const;
  void setIcon(const QString &icon);

private:
  QString _main = "";
  QString _description = "";
  QString _icon = "";
};

WEATHER_LIB_NAMESPACE_END

#endif // OPENWEATHERWEATHERRESPONSE_H
