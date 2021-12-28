#pragma once
#include "Base.h"
#include "Bala.h"
#include <vector>
using namespace std;
class Soldado :
    public Base
{
private:
    vector<Bala*>balas;
public:
    Soldado();
    ~Soldado();
    Soldado(int px, int py, int pw, int ph);
    void Mover(Graphics^ g);
    void Disparar();
    void Mover_balas(Graphics^ g, Bitmap^ bmp);
   
    vector<Bala*> retornar_bala();
    int retornar_cant_balas();
    Bala* retornar_bala_eninidice(int indice);
};

