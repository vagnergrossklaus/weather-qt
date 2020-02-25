#ifndef TEMPERATURECONVERTER_H
#define TEMPERATURECONVERTER_H

#include "commons/domain/temperatureunitenum.h"

WEATHER_LIB_NAMESPACE_BEGIN

class TemperatureConverter {
public:
  static double convert(const double temperature,
                        const TemperatureUnitEnum &fromTemperatureUnit,
                        const TemperatureUnitEnum &toTemperatureUnit);

private:
  TemperatureConverter();
};

WEATHER_LIB_NAMESPACE_END

#endif // TEMPERATURECONVERTER_H
