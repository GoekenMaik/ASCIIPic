#ifndef IMAGEBUILDER_H
#define IMAGEBUILDER_H

#include "Definitions.h"

class ImageBuilder
{
protected:
    std::vector<std::vector<RGBTRIPLE>> image;
    FILE *inptr;
    int width;
    int height;
    std::string filename;
    virtual void initialize() = 0;

public:
    ImageBuilder(std::string filename);
    virtual int getWidth();
    virtual int getHeight();
    virtual std::vector<std::vector<RGBTRIPLE>> *getImage();
};

// IMAGEBUILDER_H
#endif