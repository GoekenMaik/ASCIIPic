#ifndef PNGBUILDER_H
#define PNGBUILDER_H

#include "ImageBuilder.h"
#include <png.h>
#include <zlib.h>

class PNGBuilder : public ImageBuilder{
    private:
        png_structp png_ptr;
        png_infop info_ptr;
        void initialize() override;
    public:
        PNGBuilder(std::string filename);
};

//PNGBUILDER_H
#endif