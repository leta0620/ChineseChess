#include "Board.h"

Board::Board()
{
	// ----- 初始化 board boardinfo 大小-----
	board.resize(10);
	boardinfo.resize(10);
	for (int y = 0; y < 10; y++)
	{
		board[y].resize(9);
		boardinfo[y].resize(9);
	}
	// --------------------------------------
	AllSet();
}
void Board::AllSet() {
	// --------------初始化版面--------------
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = NULL;
			boardinfo[i][j] = 0;
		}
	}
	// --------------------------------------
	
	// ------------黑方初始化版面------------
	board[0][0] = &B3_0;
	board[0][1] = &B4_0;
	board[0][2] = &B2_0;
	board[0][3] = &B1_0;
	board[0][4] = &B0;
	board[0][5] = &B1_1;
	board[0][6] = &B2_1;
	board[0][7] = &B4_1;
	board[0][8] = &B3_1;
	board[2][1] = &B5_0;
	board[2][7] = &B5_1;
	board[3][0] = &B6_0;
	board[3][2] = &B6_1;
	board[3][4] = &B6_2;
	board[3][6] = &B6_3;
	board[3][8] = &B6_4;
	B3_0.PreSet(0, 0, false);
	B4_0.PreSet(1, 0, false);
	B2_0.PreSet(2, 0, false);
	B1_0.PreSet(3, 0, false);
	B0.PreSet(4, 0, false);
	B1_1.PreSet(5, 0, false);
	B2_1.PreSet(6, 0, false);
	B4_1.PreSet(7, 0, false);
	B3_1.PreSet(8, 0, false);
	B5_0.PreSet(1, 2, false);
	B5_1.PreSet(7, 2, false);
	B6_0.PreSet(0, 3, false);
	B6_1.PreSet(2, 3, false);
	B6_2.PreSet(4, 3, false);
	B6_3.PreSet(6, 3, false);
	B6_4.PreSet(8, 3, false);
	// --------------------------------------
	// ------------紅方初始化版面------------
	board[9][0] = &R3_0;
	board[9][1] = &R4_0;
	board[9][2] = &R2_0;
	board[9][3] = &R1_0;
	board[9][4] = &R0;
	board[9][5] = &R1_1;
	board[9][6] = &R2_1;
	board[9][7] = &R4_1;
	board[9][8] = &R3_1;
	board[7][1] = &R5_0;
	board[7][7] = &R5_1;
	board[6][0] = &R6_0;
	board[6][2] = &R6_1;
	board[6][4] = &R6_2;
	board[6][6] = &R6_3;
	board[6][8] = &R6_4;
	R3_0.PreSet(0, 9, true);
	R4_0.PreSet(1, 9, true);
	R2_0.PreSet(2, 9, true);
	R1_0.PreSet(3, 9, true);
	R0.PreSet(4, 9, true);
	R1_1.PreSet(5, 9, true);
	R2_1.PreSet(6, 9, true);
	R4_1.PreSet(7, 9, true);
	R3_1.PreSet(8, 9, true);
	R5_0.PreSet(1, 7, true);
	R5_1.PreSet(7, 7, true);
	R6_0.PreSet(0, 6, true);
	R6_1.PreSet(2, 6, true);
	R6_2.PreSet(4, 6, true);
	R6_3.PreSet(6, 6, true);
	R6_4.PreSet(8, 6, true);
	// ---------------------------------------
	// ------------初始化Boardinfo------------
	for (int j = 0; j < 9; j++)
	{
		boardinfo[0][j] = 1;
		boardinfo[9][j] = 2;
	}
	for (int j = 0; j < 9; j += 2)
	{
		boardinfo[3][j] = 1;
		boardinfo[6][j] = 2;
	}
	for (int j = 1; j <= 7; j += 6)
	{
		boardinfo[2][j] = 1;
		boardinfo[7][j] = 2;
	}
	// ---------------------------------------
}
std::vector<Pos> Board::CanMovePos(Pos P) {
	std::vector<Pos> Position;
	Position = board[P.y][P.x]->CanMove(P,boardinfo);
	// ------------王不見王------------
	if (board[P.y][P.x]->GetName()==0) {
		if (!board[P.y][P.x]->GetColor()) { // 顏色判斷
			for (int i = P.y + 1; i <= 9; i++) {
				if (board[i][P.x] != NULL && board[i][P.x]->GetName()==0) {
					Pos tmp(P.x,i);
					Position.push_back(tmp);
				}
				else if (board[i][P.x] != NULL) {
					break;
				}
			}
		}
		else{
			for (int i = P.y - 1; i >= 0; i--) {
				if (board[i][P.x] != NULL && board[i][P.x]->GetName() == 0) {
					Pos tmp(P.x, i);
					Position.push_back(tmp);
				}
				else if (board[i][P.x] != NULL) {
					break;
				}
			}
		}
	}
	// --------------------------------
	return Position;
}
void Board::MovePos(Pos PosFirst, Pos PosSecond) {
	Chess* temp;
	board[PosFirst.y][PosFirst.x]->SetPos(PosSecond); //更改位置
	//-----board 指標移動位置-----
	temp = board[PosFirst.y][PosFirst.x]; 
	board[PosSecond.y][PosSecond.x] = temp;
	board[PosFirst.y][PosFirst.x] = NULL;
	//----------------------------
	
	//-----boardinfo移動位置------
	boardinfo[PosSecond.y][PosSecond.x] = boardinfo[PosFirst.y][PosFirst.x];
	boardinfo[PosFirst.y][PosFirst.x] = 0;
	//----------------------------
}