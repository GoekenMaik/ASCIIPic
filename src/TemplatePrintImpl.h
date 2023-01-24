#ifndef TemplatePRINTIMPL_H
#define TemplatePRINTIMPL_H

#include "TemplatePrint.h"
#include "Definitions.h"

class TemplatePrintImpl : public TemplatePrint
{
public:
    TemplatePrintImpl(std::string filename, bool lightTheme, int blockWidth);
    void printImage() override;
};

//TemplatePRINTIMPL_H
#endif