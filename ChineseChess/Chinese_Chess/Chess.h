#pragma once
#include "Pos.h"
#include <vector>

// 棋子父類別
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
	Pos pos;	// 位置
	bool color; // 紅為true，黑為false
	int name; // 0~6 將士象車馬砲卒
};