#pragma once

// 座標物件
class Pos
{
public:
	Pos();
	Pos(int x, int y);

	// 重載==
	bool operator==(Pos& a);

	int x;
	int y;
};