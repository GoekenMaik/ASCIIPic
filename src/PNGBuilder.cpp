#include "PNGBuilder.h"

PNGBuilder::PNGBuilder(std::string filename) : ImageBuilder(filename)
{
    initialize();
}

void PNGBuilder::initialize(){
        //Skip first 8 bytes of header
    char head[8];
    fread(head, 1, 8, inptr);
    
    // Read header files and create necessary structs
    png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    info_ptr = png_create_info_struct(png_ptr);

    if (setjmp(png_jmpbuf(png_ptr)))
        printf("[read_png_file] Error during init_io");

    png_init_io(png_ptr, inptr);
    png_set_sig_bytes(png_ptr, 8);
    png_read_info(png_ptr, info_ptr);
    png_read_update_info(png_ptr, info_ptr);
    width = png_get_image_width(png_ptr, info_ptr);
    height = png_get_image_height(png_ptr, info_ptr);
    png_bytep *row_pointers = (png_bytep *)malloc(sizeof(png_bytep) * height);

    // Create memory to read into array
    for (int y = 0; y < height; y++)
        row_pointers[y] = (png_byte *)malloc(png_get_rowbytes(png_ptr, info_ptr));

    // Read image into array
    png_read_image(png_ptr, row_pointers);

    // Create memory to read into vector
    char control = 0;
    for (int i = 0; i < height; i++)
    {
        std::vector<RGBTRIPLE> tmp(width);
        image.push_back(tmp);
    }

    // Read image into vector
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width * 4; j++)
        {
            switch (control)
            {
            case 0:
                image[height - i - 1][(j / 4) + 1].rgbtRed = row_pointers[i][j];
                break;
            case 1:
                image[height - i - 1][(j / 4) + 1].rgbtGreen = row_pointers[i][j];
                break;
            case 2:
                image[height - i - 1][(j / 4) + 1].rgbtBlue = row_pointers[i][j];
                break;
            }
            control = j % 4;
        }
    }

    // free array
    for (int y = 0; y < height; y++)
        free(row_pointers[y]);
}