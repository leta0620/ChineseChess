#include "Pos.h"

Pos::Pos()
{
	x = 0;
	y = 0;
}

Pos::Pos(int x, int y)
{
	this->x = x;
	this->y = y;
}

// ==­«¸ü
bool Pos::operator==(Pos& a)
{
	if (a.x == this->x && a.y == this->y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
