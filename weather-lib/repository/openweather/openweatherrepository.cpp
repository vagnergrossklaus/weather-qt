#include "openweatherrepository.h"

#include <QtNetwork>

WEATHER_LIB_NAMESPACE_BEGIN

WeatherModel *OpenWeatherRepository::current(
    const QString &city, const QString &country,
    const QLocale::MeasurementSystem &measurementUnitSystem) {

  QJsonObject object =
      makeRequest(currentWeatherUrl(city, country, measurementUnitSystem))
          .object();

  WeatherModel *weatherModel = new WeatherModel();
  weatherModel->setDate(QDate::currentDate());

  QJsonObject main = object["main"].toObject();
  weatherModel->setCurrentTemperature(main["temp"].toDouble());
  weatherModel->setMinimumTemperature(main["temp_min"].toDouble());
  weatherModel->setMaximumTemperature(main["temp_max"].toDouble());

  return weatherModel;
}

QVector<WeatherModel *> OpenWeatherRepository::forecast(
    const QString & /*city*/, const QString & /*country*/,
    const QLocale::MeasurementSystem & /*measurementUnitSystem*/) {

  return {}; // API OpenWeather é paga
}

QString OpenWeatherRepository::unitParam(
    const QLocale::MeasurementSystem &measurementUnitSystem) {
  return QString(OpenWeatherRepository::OPEN_WEATHER_UNIT_PARAM)
      .arg(measurementUnitSystem == QLocale::MetricSystem
               ? OpenWeatherRepository::OPEN_WEATHER_UNIT_METRIC_VALUE
               : OpenWeatherRepository::OPEN_WEATHER_UNIT_IMPERIAL_VALUE);
}

QString OpenWeatherRepository::forecastCountParam(const int count) {
  return QString(OpenWeatherRepository::OPEN_WEATHER_FORECAST_COUNT).arg(count);
}

QString OpenWeatherRepository::cityCountryParam(const QString &city,
                                                const QString &country) {
  return country.isEmpty()
             ? QString(OpenWeatherRepository::OPEN_WEATHER_CITY_PARAM).arg(city)
             : QString(OpenWeatherRepository::OPEN_WEATHER_CITY_COUNTRY_PARAM)
                   .arg(city)
                   .arg(country);
}

QString OpenWeatherRepository::currentWeatherUrl(
    const QString &city, const QString &country,
    const QLocale::MeasurementSystem &measurementUnitSystem) {
  return QString(OpenWeatherRepository::OPEN_WEATHER_CURRENT_URL)
      .arg(cityCountryParam(city, country))
      .arg(unitParam(measurementUnitSystem))
      .arg(QString(OpenWeatherRepository::OPEN_WEATHER_APP_ID_PARAM)
               .arg(apiKey()));
}

QString OpenWeatherRepository::forecastWeatherUrl(
    const QString &city, const QString &country,
    const QLocale::MeasurementSystem &measurementUnitSystem) {
  {
    return QString(OpenWeatherRepository::OPEN_WEATHER_CURRENT_URL)
        .arg(cityCountryParam(city, country))
        .arg(unitParam(measurementUnitSystem))
        .arg(forecastCountParam(3))
        .arg(QString(OpenWeatherRepository::OPEN_WEATHER_APP_ID_PARAM)
                 .arg(apiKey()));
  }
}

QJsonDocument OpenWeatherRepository::makeRequest(const QString &url) {
  QNetworkRequest request(QUrl(url.toUtf8()));
  QNetworkAccessManager *manager = new QNetworkAccessManager();

  QNetworkReply *reply = manager->get(request);

  QEventLoop loop;
  QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
  loop.exec();

  return QJsonDocument::fromJson(reply->readAll());
}

WEATHER_LIB_NAMESPACE_END
