#ifndef SETTINGSREPOSITORY_H
#define SETTINGSREPOSITORY_H

#include "weather-lib_global.h"

#include <QString>

WEATHER_LIB_NAMESPACE_BEGIN

class SettingsModel;
class SettingsRepository {
public:
  SettingsRepository();

  void insert(SettingsModel *settings);
  SettingsModel *find();

private:
  QString _filePath = "";

  static constexpr const char *FILE_NAME = "app.conf";

  static constexpr const char *GENERAL_GROUP = "GENERAL";
  static constexpr const char *GENERAL_API_KEY = "API_KEY";
  static constexpr const char *FORECAST_COUNT = "FORECAST_COUNT";

  static constexpr const char *LOCATION_GROUP = "LOCATION";
  static constexpr const char *LOCATION_CITY = "CITY";
  static constexpr const char *LOCATION_COUNTRY = "COUNTRY";
  static constexpr const char *LOCATION_MEASUREMENT_SYSTEM =
      "MEASUREMENT_SYSTEM";
};

WEATHER_LIB_NAMESPACE_END

#endif // SETTINGSREPOSITORY_H
