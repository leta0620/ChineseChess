#pragma once
#include "Chess.h"

// ?h?B?K
class Chess1 : public Chess
{
public:
	Chess1() {
		name = 1; 
	}
	virtual std::vector<Pos> CanMove(Pos P, std::vector<std::vector<int>> Boardinfo);
};
