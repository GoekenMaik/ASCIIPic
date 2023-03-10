#ifndef BMPBUILDER_H
#define BMPBUILDER_H

#include "ImageBuilder.h"

typedef uint8_t BYTE;
typedef uint32_t DWORD;
typedef int32_t LONG;
typedef uint16_t WORD;

typedef struct
{
  WORD bfType;
  DWORD bfSize;
  WORD bfReserved1;
  WORD bfReserved2;
  DWORD bfOffBits;
} __attribute__((__packed__))
BITMAPFILEHEADER;

typedef struct
{
  DWORD biSize;
  LONG biWidth;
  LONG biHeight;
  WORD biPlanes;
  WORD biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG biXPelsPerMeter;
  LONG biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} __attribute__((__packed__))
BITMAPINFOHEADER;

class BMPBuilder : public ImageBuilder
{
private:
  BITMAPFILEHEADER bf;
  BITMAPINFOHEADER bi;
  void initialize() override;
public:
  BMPBuilder(std::string filename);
};

// BMPBUILDER_H
#endif