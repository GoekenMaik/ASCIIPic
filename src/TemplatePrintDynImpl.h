#ifndef TemplatePRINTDYNIMPL_H
#define TemplatePRINTDYNIMPL_H

#include "Definitions.h"
#include "TemplatePrint.h"

class TemplatePrintDynImpl : public TemplatePrint
{
private:
    inline void setMinMax(float* min, float* max, float brightness);
public:
    TemplatePrintDynImpl(std::string filename, bool lightTheme, int blockWidth);
    void printImage() override;

};

//TemplatePRINTDYNIMPL_H
#endif