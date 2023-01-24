#include "BMPBuilder.h"

BMPBuilder::BMPBuilder(std::string filename) : ImageBuilder(filename)
{
  initialize();
}

void BMPBuilder::initialize()
{
  // Read header files
  fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
  fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
  width = bi.biWidth;
  height = bi.biHeight;
  int size = (int)(bi.biWidth * sizeof(RGBTRIPLE));

  // Load image into vector
  for (int i = 0; i < bi.biHeight; i++)
  {

    std::vector<RGBTRIPLE> tmp(size);
    for (int j = 0; j < bi.biWidth; j++)
    {
      fread(&tmp[j], sizeof(RGBTRIPLE), 1, inptr);
    }
    image.push_back(tmp);
  }
}