#pragma once
#include "Chess.h"

// ¨ò¡B§L
class Chess6 : public Chess
{
public:
	Chess6();
	~Chess6();

	virtual std::vector<Pos> MoveLegal();
};
