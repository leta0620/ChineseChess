#pragma once
#include "Chess.h"

// ¶H¡B¹³
class Chess2 : public Chess
{
public:
	Chess2();
	~Chess2();

	virtual std::vector<Pos> MoveLegal();
};

