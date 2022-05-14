#pragma once
#include "Chess.h"

// 車、俥
class Chess3 : public Chess
{
public:
	Chess3();
	~Chess3();

	virtual std::vector<Pos> MoveLegal();
};

