#include "JPEGBuilder.h"

JPEGBuilder::JPEGBuilder(std::string filename) : ImageBuilder(filename)
{
    initialize();
}

void JPEGBuilder::initialize()
{
    /* Initialize necessary structs,
     ask for RGB values */
    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, inptr);
    jpeg_read_header(&cinfo, FALSE);
    jpeg_start_decompress(&cinfo);
    cinfo.jpeg_color_space = JCS_RGB;
    width = cinfo.output_width;
    height = cinfo.output_height;
    int RGBWidth = width * 3;
    char control = 0;

    // Create memory to read into vector
    for (int i = 0; i < cinfo.output_height; i++)
    {
        std::vector<RGBTRIPLE> tmp(width);
        image.push_back(tmp);
    }
    
    // create memory to read into array
    JSAMPROW row = (JSAMPROW)malloc(sizeof(HAVE_UNSIGNED_CHAR) * RGBWidth);
    for (int i = 1; i <= cinfo.output_height; i++)
    {
        // Read scanline into array
        jpeg_read_scanlines(&cinfo, &row, 1);
        // Write array into vector
        for (int j = 0; j <= RGBWidth; j++)
        {
            switch (control)
            {
            case 0:
                image[cinfo.output_height - i][(j / 3) + 1].rgbtRed = row[j];
                break;
            case 1:
                image[cinfo.output_height - i][(j / 3) + 1].rgbtGreen = row[j];
                break;
            case 2:
                image[cinfo.output_height - i][(j / 3) + 1].rgbtBlue = row[j];
                break;
            }
            control = j % 3;
        }
    }
}