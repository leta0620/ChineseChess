#pragma once
#include "Chess.h"

// ���B�X
class Chess4 : public Chess
{
public:
	Chess4() {
		name = 4;
	}
	virtual std::vector<Pos> CanMove(Pos P, std::vector<std::vector<int>> Boardinfo);
};

