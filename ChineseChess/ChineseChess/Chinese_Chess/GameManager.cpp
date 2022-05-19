#include "GameManager.h"

std::string GetTime()
{
	time_t t = time(0);
	char tmp[64];
	strftime(tmp, sizeof(tmp), "%Y%m%d %H_%M_%S", localtime(&t));
	std::string s = tmp;
	return s;
}

//----------------------------------------

// 建構子
GameManager::GameManager()
{
	this->nowMovChess.x = 0;
	this->nowMovChess.y = 0;
	this->fileName = GetTime() + ".txt";
	this->gamePlayer = true;

	std::vector<Pos> newLigalList;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (boardGM.board[y][x] != NULL)
			{
				if (boardGM.board[y][x]->GetColor() == gamePlayer)
				{
					newLigalList.push_back(boardGM.board[y][x]->GetPos());
				}
			}		
		}
	}
	this->ligalPos = newLigalList;
}

// 標出可移動的位置
void GameManager::clickChess(Pos pos)
{
	// 設置目前移動的位子是哪一顆棋子
	this->nowMovChess = pos;

	// 找出可移動的位置
	this->ligalPos = boardGM.CanMovePos(pos);
	return;
}

// 移動棋子，並將另一方的棋子設為合法，存log
void GameManager::moveChess(Pos pos)
{
	// 移動棋子
	boardGM.MovePos(this->nowMovChess, pos);

	// 出log檔
	if (!file.is_open())
	{
		file.open(this->fileName);
	}
	//file.open(this->fileName);

	if (boardGM.board[pos.y][pos.x]->GetColor() == false)
	{
		file << "Black";
	}
	else if (boardGM.board[pos.y][pos.x]->GetColor() == true)
	{
		file << "Red";
	}
	file << " " << boardGM.board[pos.y][pos.x]->GetName() <<
		" move from (" << nowMovChess.x << ", " << nowMovChess.y <<
		") to (" << pos.x << ", " << pos.y << ")\n";
	// file.close();

	// 重置參數
	this->nowMovChess.x = 0;
	this->nowMovChess.y = 0;
	this->gamePlayer = !this->gamePlayer;	// 切換玩家

	// 更改ligalList
	std::vector<Pos> newLigalList;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (boardGM.board[y][x] != NULL)
			{
				if (boardGM.board[y][x]->GetColor() == gamePlayer)
				{
					newLigalList.push_back(boardGM.board[y][x]->GetPos());
				}
			}
		}
	}
	this->ligalPos = newLigalList;

	return;
}
// 判斷勝負
bool GameManager::Win()
{
	// 如果獲勝，記得gameover
	return true;
}
// 是否將軍
bool GameManager::WillWin()
{
	return true;
}

// 獲取ligalPos
std::vector<Pos> GameManager::GetLigalPos()
{
	return this->ligalPos;
}

// 設定ligalPos
void GameManager::SetLigalPos(std::vector<Pos> ligalPos)
{
	this->ligalPos = ligalPos;
}

// 結束遊戲
void GameManager::GameOver()
{
	this->gameStart = false;
	this->file.close();
}

// 重新開始遊戲
void GameManager::ResetGame()
{
	Board tmpB;
	this->boardGM = tmpB;
	this->gamePlayer = true;

	std::vector<Pos> newLigalList;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (boardGM.board[y][x] != NULL)
			{
				if (boardGM.board[y][x]->GetColor() == gamePlayer)
				{
					newLigalList.push_back(boardGM.board[y][x]->GetPos());
				}
			}
		}
	}
	this->ligalPos = newLigalList;

	this->fileName = GetTime() + ".txt";
}

// 讀取遊戲是否開始
bool GameManager::GetGameStart()
{
	return this->gameStart;
}

// 設定遊戲開始
void GameManager::SetGameStart(bool in)
{
	this->gameStart = in;
}