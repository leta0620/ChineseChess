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
	void Setalive(bool);

	Pos GetPos();
	bool GetColor();
	int GetName();
	bool Getalive();
	
protected:
	Pos pos;	// 位置
	bool color = false; // 紅為true，黑為false
	int name = 0; // 0~6 將士象車馬砲卒
	bool alive = true;
};