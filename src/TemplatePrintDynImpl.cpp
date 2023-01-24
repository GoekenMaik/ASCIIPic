#include "TemplatePrintDynImpl.h"

void TemplatePrintDynImpl::printImage()
{

    // Calculate height based on width to preserve height-width ratio
    float ratio = (float)height / (float)width;
    float blockHeight = (ratio * (float)blockWidth);
    float blockGapY = (float)height / blockHeight;
    float blockGapX = (float)width / (float)blockWidth;
    float modX = fmod(width, blockGapX);
    float modY = fmod(height, blockGapY);

    /* Get Minimum brightness and Maximum brightness to adjust the range of the brightness of blocks to increase contrast */
    float min = 255;
    float max = 0;

    // Loop over BlockHeight
    for (float blockY = height - 1; blockY > blockGapY; blockY -= blockGapY)
    {
        // Loops over BlockWidth
        for (float blockX = 0; blockX < (width - modX); blockX += blockGapX)
        {
            setMinMax(&min, &max, getChunkAverage(blockY, blockX, blockGapY, blockGapX));
        }
        if (modX / blockGapX > 0.5)
        {
            setMinMax(&min, &max, getChunkAverage(blockY, width - modX, blockGapY, modX));
        }
    }
    if (modY / blockGapY > 0.5)
    {
        for (float blockX = 0; blockX < width - modX; blockX += blockGapX)
        {
            setMinMax(&min, &max, getChunkAverage(modY, blockX, modY, blockGapX));
        }
        if (modX / blockGapX > 0.5)
        {
            setMinMax(&min, &max, getChunkAverage(modY, width - modX, modY, modX));
        }
    }

    // Prints the image based on adjusted brightness
    //  Loops over BlockHeight
    for (float blockY = height - 1; blockY > blockGapY; blockY -= blockGapY)
    {
        // Loops over BlockWidth
        for (float blockX = 0; blockX < (width - modX); blockX += blockGapX)
        {
            printChar(255 * (getChunkAverage(blockY, blockX, blockGapY, blockGapX) - min) / (max - min) + 0.5);
        }
        // if the last block is cut off in the x direction and is bigger than half a block, print it
        if (modX / blockGapX > 0.5)
        {
            printChar(255 * (getChunkAverage(blockY, width - modX, blockGapY, modX) - min) / (max - min) + 0.5);
        }
        putchar('\n');
    }

    // if the last block is cut off in the y direction and is bigger than half a block, print it
    if (modY / blockGapY > 0.5)
    {
        for (float blockX = 0; blockX < width - modX; blockX += blockGapX)
        {
            printChar(255 * (getChunkAverage(modY, blockX, modY, blockGapX) - min) / (max - min) + 0.5);
        }
        if (modX / blockGapX > 0.5)
        {
            printChar(255 * (getChunkAverage(modY, width - modX, modY, modX) - min) / (max - min) + 0.5);
        }
        putchar('\n');
    }
}

void TemplatePrintDynImpl::setMinMax(float *min, float *max, float brightness)
{
    if (brightness < *min)
    {
        *min = brightness;
    }
    if (brightness > *max)
    {
        *max = brightness;
    }
}

TemplatePrintDynImpl::TemplatePrintDynImpl(std::string filename, bool lightTheme, int blockWidth) : TemplatePrint(filename, lightTheme, blockWidth)
{
}