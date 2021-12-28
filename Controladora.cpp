#include "Controladora.h"

Controladora::Controladora()
{
	objM=new Soldado(200, 200, 20, 20);
	Inicio = time(0);
}

Controladora::~Controladora()
{
}

void Controladora::Dibujar_Soldado(Graphics^ g, Bitmap^ bmp)
{
	objM->Dibujar_desImagen(g, bmp);
	objM->Mover(g);
}

void Controladora::Desplazar_Soldado(direccion nuevo)
{
	objM->Desplazamiento(nuevo);
	Colision1();
	Colision2();
}

bool Controladora::Colision1()
{
	Rectangle rsoldado = objM->retonar_rectangle();
	bool resultado_colision1 = false;
	for (int i = 0; !resultado_colision1 && i < objM->retornar_cant_balas(); i++)
	{
		Rectangle rbalas = objM->retornar_bala_eninidice(i)->retonar_rectangle();
		for (int j = 0; !resultado_colision1 && j < doradac.size(); j++)
		{
			Rectangle rnavesenemigas = doradac.at(j)->retonar_rectangle();
			if (rbalas.IntersectsWith(rnavesenemigas))
			{
				resultado_colision1 = true;
				objM->retornar_bala_eninidice(i)->cambiar_eliminar(true);
				doradac.at(j)->cambiar_vidas(doradac.at(j)->retornar_vidas() - 1);
				if(doradac.at(j)->retornar_vidas()<0)doradac.erase(doradac.begin() + j);
				
			}
		}
		for (int j = 0; !resultado_colision1 && j < dorada.size(); j++)
		{
			Rectangle rnavesenemigas = dorada.at(j)->retonar_rectangle();
			if (rbalas.IntersectsWith(rnavesenemigas))
			{
				resultado_colision1 = true;
				objM->retornar_bala_eninidice(i)->cambiar_eliminar(true);
				dorada.at(j)->cambiar_vidas(dorada.at(j)->retornar_vidas() - 1);
				if (dorada.at(j)->retornar_vidas() < 0)dorada.erase(dorada.begin() + j);

			}
		}
	}

	return resultado_colision1;
}

bool Controladora::Colision2()
{
	Rectangle rsoldado = objM->retonar_rectangle();
	bool resultado_colision2 = false;
	for (int i = 0; !resultado_colision2 && i < objM->retornar_cant_balas(); i++)
	{
		Rectangle rbalas = objM->retornar_bala_eninidice(i)->retonar_rectangle();
		for (int j = 0; !resultado_colision2 && j < plateadac.size(); j++)
		{
			Rectangle rnavesenemigas = plateadac.at(j)->retonar_rectangle();
			if (rbalas.IntersectsWith(rnavesenemigas))
			{
				resultado_colision2 = true;
				objM->retornar_bala_eninidice(i)->cambiar_eliminar(true);
				plateadac.at(j)->cambiar_vidas(plateadac.at(j)->retornar_vidas() - 2);
				if (plateadac.at(j)->retornar_vidas() <= 0)plateadac.erase(plateadac.begin() + j);

			}
		}
	}

	return resultado_colision2; 
}

void Controladora::Disparar()
{
	objM->Disparar();
}

void Controladora::Dibujar_Bala(Graphics^ g, Bitmap^ bmp)
{
	objM->Mover_balas(g, bmp);
}

void Controladora::Insertar_Monedas()
{
	System::Random^ r = gcnew System::Random();
	int a, e, f, g;
	float b, c, d;
	a = 1 + rand() % (4 + 1 - 1);
	b = 1 / 100 + rand() % (1 / 10 + 1 - 1 / 100);
	c = 1 / 100 + rand() % (1 / 10 + 1 - 1 / 100);
	d = 1 / 100 + rand() % (1 / 10 + 1 - 1 / 100);
	e = 50 + rand() % (600 + 1 - 50);
	f = 50 + rand() % (600 + 1 - 50);
	g = 50 + rand() % (600 + 1 - 50);
	int tipo = a;
	if (tipo == 1)
	{
		if (difftime(time(0), Inicio) > b)
		{
			doradac.push_back(new DoradaC(e, 0, 1, 1));
			Inicio = time(0);
		}
	}
	if (tipo == 2)
	{
		if (difftime(time(0), Inicio) > c)
		{
			plateadac.push_back(new PlateadaC(f, 0, 1, 1));
			Inicio = time(0);
		}
	}
	if (tipo == 3)
	{
		if (difftime(time(0), Inicio) > d)
		{
			dorada.push_back(new Dorada(g, 0, 1, 1));
			Inicio = time(0);
		}
	}
}

void Controladora::Dibujar_DoradaC(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < doradac.size(); i++)
	{
		doradac.at(i)->Dibujar_desImagen(g, bmp);
		doradac.at(i)->Mover(g);
	}
	for (int i = 0; i < doradac.size(); i++)
	{
		if (doradac.at(i)->retornar_eliminar() == true)
			doradac.erase(doradac.begin() + i);
	}
}

void Controladora::Dibujar_PlateadaC(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < plateadac.size(); i++)
	{
		plateadac.at(i)->Dibujar_desImagen(g, bmp);
		plateadac.at(i)->Mover(g);
	}
	for (int i = 0; i < plateadac.size(); i++)
	{
		if (plateadac.at(i)->retornar_eliminar() == true)
			plateadac.erase(plateadac.begin() + i);
	}
}

void Controladora::Dibujar_Dorada(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < dorada.size(); i++)
	{
		dorada.at(i)->Dibujar_desImagen(g, bmp);
		dorada.at(i)->Mover(g);
	}
	for (int i = 0; i < dorada.size(); i++)
	{
		if (dorada.at(i)->retornar_eliminar() == true)
			dorada.erase(dorada.begin() + i);
	}
}
