#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

#include "weather-lib_global.h"

WEATHER_LIB_NAMESPACE_BEGIN

class SettingsModel;
class SettingsController {
public:
  SettingsController();

  SettingsModel *find();
};

WEATHER_LIB_NAMESPACE_END

#endif // SETTINGSCONTROLLER_H
