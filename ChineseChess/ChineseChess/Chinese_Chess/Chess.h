#pragma once
#include "Pos.h"
#include <vector>

// 棋子父類別
class Chess
{
public:
	void PreSet(int x, int y, bool Chesscolor);
	void SetPos(Pos);
	void SetPos(int x, int y);

	Pos GetPos();
	bool GetColor();
	int GetName();
	virtual std::vector<Pos> CanMove(Pos P, std::vector<std::vector<int>> Boardinfo)=0; // 可移動位置
protected:
	Pos pos;	// 位置
	bool color = false; // 紅為true，黑為false
	int name = 0; // 0~6 將士象車馬砲卒
};