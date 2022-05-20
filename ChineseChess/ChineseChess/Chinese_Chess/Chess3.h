#pragma once
#include "Chess.h"

// 車、俥
class Chess3 : public Chess
{
public:
	Chess3() {
		name = 3;
	}
	virtual std::vector<Pos> CanMove(Pos P, std::vector<std::vector<int>> Boardinfo);
};

