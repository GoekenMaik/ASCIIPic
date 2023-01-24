#include "TemplatePrintImpl.h"

void TemplatePrintImpl::printImage()
{
    // Calculate height based on width to preserve height-width ratio
    // Calculate height based on width to preserve height-width ratio
    float ratio = (float)height / (float)width;
    float blockHeight = (ratio * (float)blockWidth);
    float blockGapY = (float)height / blockHeight;
    float blockGapX = (float)width / (float)blockWidth;
    float modX = fmod(width, blockGapX);
    float modY = fmod(height, blockGapY);

    // Prints the image
    // Loops over BlockHeight
    for (float blockY = height - 1; blockY > blockGapY; blockY -= blockGapY)
    {
        // Loops over BlockHeight
        for (float blockX = 0; blockX < (width - modX); blockX += blockGapX)
        {
            printChar(TemplatePrint::getChunkAverage(blockY, blockX, blockGapY, blockGapX));
        }
        // if the last block is cut off in the x direction and is bigger than half a block, print it
        if (modX / blockGapX > 0.5)
        {
            printChar(TemplatePrint::getChunkAverage(blockY, width - modX, blockGapY, modX));
        }
        putchar('\n');
    }

    // if the last block is cut off in the y direction and is bigger than half a block, print it
    if (modY / blockGapY > 0.5)
    {
        for (float blockX = 0; blockX < width - modX; blockX += blockGapX)
        {
            printChar(TemplatePrint::getChunkAverage(modY, blockX, modY, blockGapX));
        }
        if (modX / blockGapX > 0.5)
        {
            printChar(TemplatePrint::getChunkAverage(modY, width - modX, modY, modX));
        }
        putchar('\n');
    }
}

TemplatePrintImpl::TemplatePrintImpl(std::string filename, bool lightTheme, int blockWidth) : TemplatePrint(filename, lightTheme, blockWidth)
{
}