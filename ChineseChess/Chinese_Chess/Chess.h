#pragma once
#include "Pos.h"
#include <vector>

// �Ѥl�����O
class Chess
{
public:
	Chess();
	Chess(Pos pos, bool color, int name);
	Chess(int x, int y, bool color, int name);
	~Chess();

	void SetPos(Pos);
	void SetPos(int x, int y);
	Pos GetPos();

	bool GetColor();

	int GetName();

	virtual std::vector<Pos> MoveLegal() = 0;

protected:
	Pos pos;	// ��m
	bool color; // ����true�A�¬�false
	int name; // 0~6 �N�h�H��������
};