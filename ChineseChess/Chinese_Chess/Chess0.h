#pragma once
#include "Chess.h"

// �N�B��
class Chess0 : public Chess
{
public:
	Chess0();
	~Chess0();

	virtual std::vector<Pos> MoveLegal();
};
