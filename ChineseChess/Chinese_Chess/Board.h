#pragma once
#include <vector>
#include "Chess.h"

// 盤面中的物件
struct BoardItem
{
	// 是否為合法位置
	bool ligal = false;
	// 棋子，若無棋子為0
	Chess* chess = 0;
};

class Board
{
public:
	// 預設建構子
	Board();
	// 傳入目前的棋子、需要標示合法的位置
	Board(std::vector<Chess*> allChess, std::vector<Pos> ligalPos);

private:
	// 盤面變數
	std::vector<std::vector<BoardItem>> board;
};