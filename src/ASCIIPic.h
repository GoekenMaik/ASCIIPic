#ifndef ASCIIPIC_H
#define ASCIIPIC_H

#include <cstring>
#include "Definitions.h"
#include "TemplatePrint.h"
#include "TemplatePrintImpl.h"
#include "TemplatePrintDynImpl.h"

class ASCIIPic
{
private:
    TemplatePrint *printer;

public:
    int run(int argc, char *argv[]);
};

//ASCIIPIC_H
#endif