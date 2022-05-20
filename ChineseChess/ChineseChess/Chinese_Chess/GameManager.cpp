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

	std::vector<Pos> newLegalList;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (boardGM.board[y][x] != NULL)
			{
				if (boardGM.board[y][x]->GetColor() == gamePlayer)
				{
					newLegalList.push_back(boardGM.board[y][x]->GetPos());
				}
			}		
		}
	}
	this->legalPos = newLegalList;
}

// 標出可移動的位置
bool GameManager::clickChess(Pos pos)
{
	// 設置目前移動的位子是哪一顆棋子
	this->nowMovChess = pos;

	// 找出可移動的位置
	std::vector<Pos> tmpPos= boardGM.CanMovePos(pos);
	if (tmpPos.empty())
	{
		return true;
	}
	else
	{
		this->legalPos = tmpPos;
		return false;
	}	
}

// 移動棋子，並將另一方的棋子設為合法，存log
void GameManager::moveChess(Pos pos)
{
	// 移動棋子
	boardGM.MovePos(this->nowMovChess, pos);

	// 輸出log檔
	if (!file.is_open())
	{
		file.open(this->fileName);
	}

	file << "Player: ";
	if (this->gamePlayer == true)
	{
		file << "1";
	}
	else if (this->gamePlayer == false)
	{
		file << "2";
	}
	file << ", Action: ";

	switch (boardGM.board[pos.y][pos.x]->GetName())
	{
	case 0:
		file << "General";
		break;
	case 1:
		file << "Advisor";
		break;
	case 2:
		file << "Elephant";
		break;
	case 3:
		file << "Chariot";
		break;
	case 4:
		file << "Horse";
		break;
	case 5:
		file << "Cannon";
		break;
	case 6:
		file << "Soldier";
		break;
	default:
		break;
	}

	file << " (" << nowMovChess.x << ", " << nowMovChess.y <<
		") -> (" << pos.x << ", " << pos.y << ")\n";

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
	this->legalPos = newLigalList;

	return;
}

// 判斷勝負
int GameManager::Win()
{
	bool Red0 = false;
	bool black0 = false;

	// 尋找棋盤，看是否有將/帥死亡
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (boardGM.board[y][x] != NULL)
			{
				if (boardGM.board[y][x]->GetName() == 0)
				{
					switch (boardGM.board[y][x]->GetColor())
					{
					case true:
						Red0 = true;
						break;
					case false:
						black0 = true;
						break;
					default:
						break;
					}
				}
			}
		}
	}

	if (Red0 == false)
	{// 紅帥死，黑方勝
		return 2;
	}
	else if (black0 == false)
	{// 黑將死，紅方勝
		return 1;
	}

	return 0;
}

// 是否將軍
int GameManager::WillWin()
{
	// 檢查盤面
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			// 若此位置有棋子
			if (boardGM.board[y][x] != NULL)
			{
				if (boardGM.board[y][x]->GetColor() == !gamePlayer)
				{
					std::vector<Pos> legalPos;
					Pos tmp(x, y);
					legalPos = boardGM.CanMovePos(tmp);

					// 檢查可移動的位置中是否有對方將/帥
					for (int check = 0; check < legalPos.size(); check++)
					{
						if (boardGM.board[legalPos[check].y][legalPos[check].x] != NULL)
						{
							if (boardGM.board[legalPos[check].y][legalPos[check].x]->GetName() == 0 && boardGM.board[legalPos[check].y][legalPos[check].x]->GetColor() == gamePlayer)
							{
								if (!gamePlayer == true)
								{
									// 紅方將軍
									return 1;
								}
								if (!gamePlayer == false)
								{
									// 黑方將軍
									return 2;
								}
							}
						}
					}
				}
			}
		}
	}

	return 0;
}


// 獲取legalPos
std::vector<Pos> GameManager::GetLegalPos()
{
	return this->legalPos;
}

// 設定legalPos
void GameManager::SetLegalPos(std::vector<Pos> legalPos)
{
	this->legalPos = legalPos;
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
	GameManager tmp;
	this->gameStart = tmp.gameStart;
	this->legalPos = tmp.legalPos;
	this->nowMovChess = tmp.nowMovChess;
	this->fileName = tmp.fileName;
	this->gamePlayer = tmp.gamePlayer;
	this->boardGM.AllSet();
	this->SetGameStart(true);
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


bool GameManager::GetGamePlayer()
{
	return gamePlayer;
}

// 讀取檔案，更改盤面
void LoadLog()
{
	std::ifstream Log;
}
