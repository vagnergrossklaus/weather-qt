#include "settingscontroller.h"

#include "service/settingsservice.h"

WEATHER_LIB_NAMESPACE_BEGIN

SettingsController::SettingsController() {}

SettingsModel *SettingsController::find() { return SettingsService().find(); }

WEATHER_LIB_NAMESPACE_END
