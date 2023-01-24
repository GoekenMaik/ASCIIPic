#ifndef STRATEGYPRINT_H
#define STRATEGYPRINT_H

#include <cmath>
#include <stdbool.h>
#include "ImageBuilder.h"
#include "BMPBuilder.h"
#include "JPEGBuilder.h"
#include "PNGBuilder.h"
#include "StrategyTheme.h"
#include "StrategyLight.h"
#include "StrategyDark.h"

#define FORMAT 4

class TemplatePrint
{
protected:
    ImageBuilder *builder;
    StrategyTheme *strategyTheme;
    std::vector<std::vector<RGBTRIPLE>> *image;
    int blockWidth;
    int width;
    int height;

    float getChunkAverage(int blockY, int blockX, float blockGapY, float blockGapX);
    void printChar(int brightness);

public:
    TemplatePrint(std::string filename, bool lightTheme, int blockWidth);
    virtual void printImage() = 0;
};

// STRATEGYPRINT_H
#endif