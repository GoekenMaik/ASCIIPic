#include "ImageBuilder.h"

ImageBuilder::ImageBuilder(std::string filename)
{
    // Open input file
    this->filename = filename;
    this->inptr = fopen(filename.c_str(), "rb");
    if (inptr == NULL)
    {
        std::cout << "Input file not opened" << std::endl;
        std::exit(0);
    }
    // Initialize vector
    image = std::vector<std::vector<RGBTRIPLE>>();
}

int ImageBuilder::getWidth()
{
    return width;
}

int ImageBuilder::getHeight()
{
    return height;
}

std::vector<std::vector<RGBTRIPLE>> *ImageBuilder::getImage()
{
    return &image;
}