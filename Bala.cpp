#include "Bala.h"
Bala::Bala()
{

}

Bala::Bala(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 4, 4, 0, 0)
{
	System::Random^ r = gcnew System::Random();
	
}

Bala::~Bala()
{
}

void Bala::Mover(Graphics^ g)
{
    if (y + dy < 1)
    {
        dy = 0;
        eliminar = true;
    }
    if (y + dy + w > g->VisibleClipBounds.Width)
    {
        dy = 0;
        eliminar = true;
    }
    if (x + dx < 1)
    {
        dx = 0;
        eliminar = true;
    }
    if (x + dx + h > g->VisibleClipBounds.Height)
    {
        dx = 0;
        eliminar = true;
    }

    y += dy;
    x += dx;
}