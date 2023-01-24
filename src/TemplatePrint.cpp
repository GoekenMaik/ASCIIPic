#include "TemplatePrint.h"

TemplatePrint::TemplatePrint(std::string filename, bool lightTheme, int blockWidth)
{
    this->blockWidth = blockWidth;

    std::string format[FORMAT] = {".jpeg", ".jpg", ".bmp", ".png"};
    // Chooses the ImageBuilder based on the type of the file

    int i = 0;
    for (; i < FORMAT; i++)
    {
        if ((filename.find(format[i]) != -1))
            break;
    }

    switch (i)
    {
    case 0:
        builder = new JPEGBuilder(filename);
        break;
    case 1:
        builder = new JPEGBuilder(filename);
        break;
    case 2:
        builder = new BMPBuilder(filename);
        break;
    case 3:
        builder = new PNGBuilder(filename);
        break;
    case 4:
        std::cout << "Wrong input\n";
        std::exit(0);
    }
    
    // Chooses the StrategyTheme based on the option -l
    if (lightTheme)
        strategyTheme = new StrategyLight();
    else
        strategyTheme = new StrategyDark();


    
    this->width = builder->getWidth();
    this->height = builder->getHeight();
    this->image = builder->getImage();
    (*image)[1][1].rgbtRed;
}

float TemplatePrint::getChunkAverage(int blockY, int blockX, float blockGapY, float blockGapX)
{
    float blockAverage = 0;
    int pixelCount = 0;
    // Loops over ChunkHeight
    for (int y = blockY; y > blockY - blockGapY; y--)
    {
        // Loops over ChunkWidth
        for (int x = blockX; x < blockX + blockGapX; x++)
        {
            blockAverage = blockAverage + (*image)[y][x].rgbtRed + (*image)[y][x].rgbtBlue + (*image)[y][x].rgbtGreen;
            pixelCount++;
        }
    }

    return blockAverage / (float)(pixelCount * 3);
}

void TemplatePrint::printChar(int brightness)
{
    switch (strategyTheme->getTheme(brightness))
    {
    case 0 ... 15:
        putchar(' ');
        putchar(' ');
        break;
    case 16 ... 31:
        putchar('.');
        putchar(' ');
        break;
    case 32 ... 47:
        putchar('.');
        putchar('.');
        break;
    case 48 ... 63:
        putchar('.');
        putchar('-');
        break;
    case 64 ... 79:
        putchar('-');
        putchar('-');
        break;
    case 80 ... 95:
        putchar('-');
        putchar(';');
        break;
    case 96 ... 111:
        putchar(';');
        putchar(';');
        break;
    case 112 ... 127:
        putchar(';');
        putchar('!');
        break;
    case 128 ... 143:
        putchar('!');
        putchar('!');
        break;
    case 144 ... 159:
        putchar('!');
        putchar('l');
        break;
    case 160 ... 175:
        putchar('l');
        putchar('l');
        break;
    case 176 ... 191:
        putchar('l');
        putchar('F');
        break;
    case 192 ... 207:
        putchar('T');
        putchar('T');
        break;
    case 208 ... 223:
        putchar('O');
        putchar('T');
        break;
    case 224 ... 239:
        putchar('O');
        putchar('O');
        break;
    case 240 ... 255:
        putchar('N');
        putchar('N');
        break;
    }
}