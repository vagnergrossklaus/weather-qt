#include "settingsservice.h"

#include "repository/settings/settingsrepository.h"

WEATHER_LIB_NAMESPACE_BEGIN

SettingsService::SettingsService() {}

SettingsModel *SettingsService::find() { return SettingsRepository().find(); }

WEATHER_LIB_NAMESPACE_END
