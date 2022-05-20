#pragma once
#include "Chess.h"

// ¯¥¡B¬¶
class Chess5 : public Chess
{
public:
	Chess5() {
		name = 5;
	}
	virtual std::vector<Pos> CanMove(Pos P, std::vector<std::vector<int>> Boardinfo);
};

