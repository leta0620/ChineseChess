#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Board.h"

// 獲取時間
std::string GetTime();

class GameManager
{
public:
	GameManager();

	// 標出可移動的位置
	void clickChess(Pos);
	// 移動棋子，並將另一方的棋子設為合法，存log
	void moveChess(Pos);
	// 判斷勝負
	bool Win();
	// 是否將軍
	bool WillWin();

	// 獲取ligalPos
	std::vector<Pos> GetLigalPos();

	// 設定ligalPos
	void SetLigalPos(std::vector<Pos> ligalPos);

	// 結束遊戲
	void GameOver();

	// 重新開始遊戲
	void ResetGame();

	// 讀取遊戲是否開始
	bool GetGameStart();

	// 設定遊戲開始
	void SetGameStart(bool in);

private:
	// 遊戲是否開始
	bool gameStart;

	// 宣告盤面物件
	Board boardGM;

	// 合法的點擊位置
	std::vector<Pos> ligalPos;
	
	// 目前正在移動的棋子
	Pos nowMovChess;

	// log檔的名稱
	std::string fileName;
	
	// log 檔
	std::ofstream file;

	// 遊戲進行到哪個階段，gamePlayer = true為紅，反之。
	bool gamePlayer;
};