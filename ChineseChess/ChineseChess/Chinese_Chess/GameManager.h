#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Board.h"
#include "Viewer.h"

// 獲取時間
std::string GetTime();

class GameManager
{
public:
	GameManager();

	//---------funtion-----------
	//
	// 標出可移動的位置
	bool clickChess(Pos);
	// 移動棋子，並將另一方的棋子設為合法，存log
	void moveChess(Pos);

	// 判斷勝負
	int Win();
	// 是否將軍
	int WillWin();
	// 獲取legalPos
	std::vector<Pos> GetLegalPos();
	// 設定legalPos
	void SetLegalPos(std::vector<Pos> legalPos);
	// 結束遊戲
	void GameOver();
	// 重新開始遊戲
	void ResetGame();
	// 讀取遊戲是否開始
	bool GetGameStart();
	// 設定遊戲開始
	void SetGameStart(bool in);
	// 讀取檔案，更改盤面
	void LoadLog();



	//-----------物件---------------
	// 
	// Viewer物件
	Viewer viewer;	
	// 宣告盤面物件
	Board boardGM;
private:
	// 遊戲是否開始
	bool gameStart;

	// 合法的點擊位置
	std::vector<Pos> legalPos;
	
	// 目前正在移動的棋子
	Pos nowMovChess;

	// log檔的名稱
	std::string fileName;
	
	// log 檔
	std::ofstream file;

	// 遊戲進行到哪個階段，gamePlayer = true為紅，反之。
	bool gamePlayer;
};