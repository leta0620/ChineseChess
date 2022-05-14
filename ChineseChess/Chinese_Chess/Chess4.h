#pragma once
#include "Chess.h"

// °¨¡BØX
class Chess4 : public Chess
{
public:
	Chess4();
	~Chess4();

	virtual std::vector<Pos> MoveLegal();
};

