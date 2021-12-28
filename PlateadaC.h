#pragma once
#include "Base.h"
class PlateadaC :
    public Base
{
public:
    PlateadaC();
    ~PlateadaC();
    PlateadaC(int px, int py, int pw, int ph);
    void Mover(Graphics^ g);
};

