#include "Soldado.h"

Soldado::Soldado()
{
}

Soldado::~Soldado()
{
}

Soldado::Soldado(int px, int py, int pw, int ph) : Base(px, py, pw, ph, 4, 4, 0, 0)
{
	fraccion_movimientoX = 5;
	fraccion_movimientoY = 5;
	orientacion = direccion::derecha;
}

void Soldado::Mover(Graphics^ g)
{
	if (x + dx<1 || x + dx + w>g->VisibleClipBounds.Width)dx = 0;
	if (y + dy<1 || y + dy + h>g->VisibleClipBounds.Height)dy = 0;
	x += dx;
	y += dy;
}

vector<Bala*> Soldado::retornar_bala()
{
	return balas;
}

int Soldado::retornar_cant_balas()
{
	return balas.size();
}

Bala* Soldado::retornar_bala_eninidice(int indice)
{
	return balas.at(indice);
}

void Soldado::Disparar()
{
	System::Random^ r = gcnew System::Random();

	balas.push_back(new Bala(x + w / 2, y, 1, 1));
	if (dx > 1)
		balas.at(balas.size() - 1)->cambiar_dx(r->Next(15, 20));
	if (dx < -1)
		balas.at(balas.size() - 1)->cambiar_dx(-(r->Next(15, 20)));
	if (dy > 1)
		balas.at(balas.size() - 1)->cambiar_dy(r->Next(15, 20));
	if (dy < -1)
		balas.at(balas.size() - 1)->cambiar_dy(-(r->Next(15, 20)));
}

void Soldado::Mover_balas(Graphics^ g, Bitmap^ bmp)
{
	for (int i = 0; i < balas.size(); i++)
	{
		balas.at(i)->Dibujar_desImagen2(g, bmp);
		balas.at(i)->Mover(g);
	}
	for (int i = 0; i < balas.size(); i++)
	{
		if (balas.at(i)->retornar_eliminar() == true)
			balas.erase(balas.begin() + i);
	}
}
