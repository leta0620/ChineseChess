#pragma once
#include "Chess.h"

// �H�B��
class Chess2 : public Chess
{
public:
	Chess2();
	~Chess2();

	virtual std::vector<Pos> MoveLegal();
};

