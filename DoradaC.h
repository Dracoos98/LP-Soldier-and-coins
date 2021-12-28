#pragma once
#include "Base.h"
class DoradaC :
    public Base
{
private:
    int vidas;
public:
    DoradaC();
    ~DoradaC();
    DoradaC(int px, int py, int pw, int ph);
    void Mover(Graphics^ g);
    
};

