#pragma once
#include "Chess.h"

// ��B�L
class Chess6 : public Chess
{
public:
	Chess6();
	~Chess6();

	virtual std::vector<Pos> MoveLegal();
};
