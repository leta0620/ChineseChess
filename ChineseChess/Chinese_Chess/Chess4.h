#pragma once
#include "Chess.h"

// ���B�X
class Chess4 : public Chess
{
public:
	Chess4();
	~Chess4();

	virtual std::vector<Pos> MoveLegal();
};

