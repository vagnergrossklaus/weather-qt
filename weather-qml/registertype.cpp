#include "registertype.h"

#include <QQmlEngine>

#include <controller/weathercontroller.h>
#include <model/weathermodel.h>

using weather::WeatherController;
using weather::WeatherModel;

RegisterType::RegisterType() {}

void RegisterType::registerType() {
  qmlRegisterType<WeatherController>("WeatherController", 1, 0,
                                     "WeatherController");

  qRegisterMetaType<QList<WeatherModel *>>("QList<WeatherModel *>");
}
