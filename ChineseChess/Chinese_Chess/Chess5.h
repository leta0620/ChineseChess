#pragma once
#include "Chess.h"

// ¯¥¡B¬¶
class Chess5 : public Chess
{
public:
	Chess5();
	~Chess5();

	virtual std::vector<Pos> MoveLegal();
};

