#include "ASCIIPic.h"

int ASCIIPic::run(int argc, char *argv[])
{
    int blockWidth = 60;
    
    bool setLightTheme = false;
    bool setDynamic = false;

    // Evaluate arguments
    if (argc < 2 || argc > 7)
    {
        std::cout << "Usage: ASCIIPic FILE [-w width] [-d] \n";
        std::exit(0);
    }

    std::string filename = argv[1];

    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-w") == 0)
        {
            if (i + 1 < argc)
                blockWidth = atoi(argv[i + 1]);
            else
            {
                std::cout << "Needs value of Width\n";
                std::exit(0);
            }
            if (blockWidth < 1 || blockWidth >= 1000)
            {
                std::cout << "Invalid Width. Must be between 1-10000\n";
                std::exit(0);
            }
        }

        if (strcmp(argv[i], "-l") == 0)
        {
            setLightTheme = true;
        }

        if (strcmp(argv[i], "-d") == 0)
        {
            setDynamic = true;
        }

        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            std::cout << "Usage: ASCIIPic FILE [-w width] [-d] \n";
            std::cout << "Options:\n";
            std::cout << "  -w width\t\tSet the width of the ASCII image. Default is 60\n";
            std::cout << "  -d\t\t\tPrints the ASCII image with adjusted brightness\n";
            std::cout << "  -l\t\t\tPrints the ASCII image for light background\n";
            std::cout << "  -h, --help\t\tPrints this help message\n";
            std::cout << "Example: ./ASCIIPic images/circle.jpeg -w 40 -d -l\n";
            std::exit(0);
        }
    }

    // Chooses the TemplatePrint based on the option -d
    if (setDynamic)
    {
        printer = new TemplatePrintDynImpl(filename, setLightTheme, blockWidth);
    }
    else
    {
        printer = new TemplatePrintImpl(filename, setLightTheme, blockWidth);
    }

    printer->printImage();
    return 0;
}