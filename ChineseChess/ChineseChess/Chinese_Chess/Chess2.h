#pragma once
#include "Chess.h"

// ¶H¡B¹³
class Chess2 : public Chess
{
public:
	Chess2() {
		name = 2;
	}
	virtual std::vector<Pos> CanMove(Pos P, std::vector<std::vector<int>> Boardinfo);
};

