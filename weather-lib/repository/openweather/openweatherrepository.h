#ifndef OPENWEATHERREPOSITORY_H
#define OPENWEATHERREPOSITORY_H

#include "repository/weatherrepository.h"

#include <QNetworkReply>

WEATHER_LIB_NAMESPACE_BEGIN

class OpenWeatherRepository : public WeatherRepository {
  using WeatherRepository::WeatherRepository;

public:
  WeatherModel *
  current(const QString &city, const QString &country,
          const QLocale::MeasurementSystem &measurementUnitSystem) override;
  QVector<WeatherModel *>
  forecast(const QString &city, const QString &country,
           const QLocale::MeasurementSystem &measurementUnitSystem) override;

private:
  static constexpr const char *OPEN_WEATHER_CURRENT_URL =
      "http://api.openweathermap.org/data/2.5/weather?%1&%2&%3";
  static constexpr const char *OPEN_WEATHER_FORECAST_DAILY_URL =
      "http://api.openweathermap.org/data/2.5/forecast/daily?%1&%2&%3&%4";

  static constexpr const char *OPEN_WEATHER_CITY_PARAM = "q=%1";
  static constexpr const char *OPEN_WEATHER_CITY_COUNTRY_PARAM = "q=%1,%2";

  static constexpr const char *OPEN_WEATHER_UNIT_PARAM = "units=%1";
  static constexpr const char *OPEN_WEATHER_UNIT_METRIC_VALUE = "metric";
  static constexpr const char *OPEN_WEATHER_UNIT_IMPERIAL_VALUE = "imperial";

  static constexpr const char *OPEN_WEATHER_FORECAST_COUNT = "cnt=%1";

  static constexpr const char *OPEN_WEATHER_APP_ID_PARAM = "appid=%1";

  QString unitParam(const QLocale::MeasurementSystem &measurementUnitSystem);
  QString forecastCountParam(const int count);
  QString cityCountryParam(const QString &city, const QString &country);
  QString
  currentWeatherUrl(const QString &city, const QString &country,
                    const QLocale::MeasurementSystem &measurementUnitSystem);
  QString
  forecastWeatherUrl(const QString &city, const QString &country,
                     const QLocale::MeasurementSystem &measurementUnitSystem);

  QJsonDocument makeRequest(const QString &url);
};

WEATHER_LIB_NAMESPACE_END

#endif // OPENWEATHERREPOSITORY_H
