#pragma once
#include "Base.h"
class Dorada :
    public Base
{
public:
    Dorada();
    ~Dorada();
    Dorada(int px, int py, int pw, int ph);
    void Mover(Graphics^ g);
};

