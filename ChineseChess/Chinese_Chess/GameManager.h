#pragma once
#include <iostream>
#include "Board.h"

class GameManager
{
public:
	GameManager();

	// 標出可移動的位置
	Board clickChess(Pos);
	// 移動棋子，並將另一方的棋子設為合法，存log
	Board moveChess(Pos);
	// 判斷勝負
	bool Win();
	// 是否將軍
	bool WillWin();

private:
	Board board;
	std::vector<Chess*> allChess;
	std::vector<Pos> ligalPos;
	// 目前正在動作的玩家顏色，0 >> red，1 >> black
	int nowMoveColor = 0;
};