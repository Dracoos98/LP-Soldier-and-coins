#include "DoradaC.h"

DoradaC::DoradaC()
{
}

DoradaC::~DoradaC()
{
}

DoradaC::DoradaC(int px, int py, int pw, int ph) :Base(px, py, pw, ph, 1, 6, 0, 0)
{
	vidas = 2;
	System::Random^ r = gcnew System::Random();
	dy = (r->Next(4, 10));
	delete r;
}

void DoradaC::Mover(Graphics^ g)
{
	if (dy + h + y > g->VisibleClipBounds.Height)
	{
		dy = 0;
		eliminar = true;
	}
	y += dy;
}


