#pragma once
#include "Soldado.h"
#include "Dorada.h"
#include "PlateadaC.h"
#include "DoradaC.h"
#include <vector>
#include <time.h>
using namespace std;
class Controladora
{
private:
	Soldado* objM;
	time_t Inicio;
	vector<Base*>doradac;
	vector<Base*>plateadac;
	vector<Base*>dorada;
	
public:
	Controladora();
	~Controladora();
	void Dibujar_Soldado(Graphics^ g, Bitmap^ bmp);
	void Desplazar_Soldado(direccion nuevo);
	bool Colision1();
	bool Colision2();
	void Disparar();
	void Dibujar_Bala(Graphics^ g, Bitmap^ bmp);
	void Insertar_Monedas();
	void Dibujar_DoradaC(Graphics^ g, Bitmap^ bmp);
	void Dibujar_PlateadaC(Graphics^ g, Bitmap^ bmp);
	void Dibujar_Dorada(Graphics^ g, Bitmap^ bmp);

};

