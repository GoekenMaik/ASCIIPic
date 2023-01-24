#ifndef JPEGBUILDER_H
#define JPEGBUILDER_H

#include "ImageBuilder.h"
#include <jpeglib.h>
#include <jerror.h>

class JPEGBuilder : public ImageBuilder
{
private:
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    void initialize() override;

public:
    JPEGBuilder(std::string filename);
};

// JPEGBuilder_H
#endif