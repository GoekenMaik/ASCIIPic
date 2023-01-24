#include "StrategyLight.h"

int StrategyLight::getTheme(int brightness)
{
    return 255 - brightness;
}
