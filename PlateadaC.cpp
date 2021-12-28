#include "PlateadaC.h"

PlateadaC::PlateadaC()
{
}

PlateadaC::~PlateadaC()
{
}

PlateadaC::PlateadaC(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 1, 6, 0, 0)
{
	vidas = 1;
	System::Random^ r = gcnew System::Random();
	dy = (r->Next(4, 10));
	delete r;
}

void PlateadaC::Mover(Graphics^ g)
{
	if (dy + h + y > g->VisibleClipBounds.Height)
	{
		dy = 0;
		eliminar = true;
	}
	y += dy;
}
