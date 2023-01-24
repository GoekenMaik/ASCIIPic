#ifndef STRATEGYLIGHT_H
#define STRATEGYLIGHT_H

#include "StrategyTheme.h"

class StrategyLight : public StrategyTheme{
    int getTheme(int brightness) override;
};

//STRATEGYLIGHT_H
#endif