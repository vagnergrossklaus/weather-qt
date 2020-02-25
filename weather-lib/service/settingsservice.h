#ifndef SETTINGSSERVICE_H
#define SETTINGSSERVICE_H

#include "weather-lib_global.h"

WEATHER_LIB_NAMESPACE_BEGIN

class SettingsModel;
class SettingsService {
public:
  SettingsService();

  SettingsModel *find();
};

WEATHER_LIB_NAMESPACE_END

#endif // SETTINGSSERVICE_H
