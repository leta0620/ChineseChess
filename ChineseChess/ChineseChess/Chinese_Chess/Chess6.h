#pragma once
#include "Chess.h"

// ¨ò¡B§L
class Chess6 : public Chess
{
public:
	Chess6() {
		name = 6;
	}
	virtual std::vector<Pos> CanMove(Pos P, std::vector<std::vector<int>> Boardinfo);
};
