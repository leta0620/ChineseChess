#pragma once
#include "Chess.h"

// ±N¡B«Ó
class Chess0 : public Chess
{
public:
	Chess0() {
		name = 0; 
	}
	virtual std::vector<Pos> CanMove(Pos P, std::vector<std::vector<int>> Boardinfo);
};
