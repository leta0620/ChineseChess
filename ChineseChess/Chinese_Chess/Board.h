#pragma once
#include <vector>
#include "Chess0.h"
#include "Chess1.h"
#include "Chess2.h"
#include "Chess3.h"
#include "Chess4.h"
#include "Chess5.h"
#include "Chess6.h"

class Board
{
public:
	// 預設建構子
	Board();
	void AllSet();
	std::vector<Pos> CanMovePos(Pos P);			// 棋子可移動的位置
	void MovePos(Pos PosFirst, Pos PosSecond);	// 移動棋子位置
	
	std::vector<std::vector<Chess*>> board; // 盤面

private:
	Chess0 B0,R0;
	Chess1 B1_0, B1_1, R1_0, R1_1;
	Chess2 B2_0, B2_1, R2_0, R2_1;
	Chess3 B3_0, B3_1, R3_0, R3_1;
	Chess4 B4_0, B4_1, R4_0, R4_1;
	Chess5 B5_0, B5_1, R5_0, R5_1;
	Chess6 B6_0, B6_1, B6_2, B6_3, B6_4, R6_0, R6_1, R6_2, R6_3, R6_4;
};