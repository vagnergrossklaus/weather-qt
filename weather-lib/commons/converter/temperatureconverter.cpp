#include "temperatureconverter.h"

WEATHER_LIB_NAMESPACE_BEGIN

TemperatureConverter::TemperatureConverter() {}

double
TemperatureConverter::convert(const double temperature,
                              const TemperatureUnitEnum &fromTemperatureUnit,
                              const TemperatureUnitEnum &toTemperatureUnit) {

  switch (fromTemperatureUnit) {

  case TemperatureUnitEnum::FAHRENHEIT: {
    switch (toTemperatureUnit) {
    case TemperatureUnitEnum::CELSIUS:
      return ((temperature - 32) * 5) / 9;
      break;
    default:
      return temperature;
    }
  }

  case TemperatureUnitEnum::CELSIUS: {
    switch (toTemperatureUnit) {
    case TemperatureUnitEnum::FAHRENHEIT:
      return ((temperature * 9) / 5) + 32;
      break;
    default:
      return temperature;
    }
  }

  case TemperatureUnitEnum::KELVIN: {
    switch (toTemperatureUnit) {
    case TemperatureUnitEnum::CELSIUS:
      return temperature - 273.15;
      break;
    default:
      return temperature;
    }
  }

  default:
    return temperature;
  }
}

WEATHER_LIB_NAMESPACE_END
