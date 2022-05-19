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

// �غc�l
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

// �ХX�i���ʪ���m
void GameManager::clickChess(Pos pos)
{
	// �]�m�ثe���ʪ���l�O���@���Ѥl
	this->nowMovChess = pos;

	// ��X�i���ʪ���m
	this->ligalPos = boardGM.CanMovePos(pos);
	return;
}

// ���ʴѤl�A�ñN�t�@�誺�Ѥl�]���X�k�A�slog
void GameManager::moveChess(Pos pos)
{
	// ���ʴѤl
	boardGM.MovePos(this->nowMovChess, pos);

	// �Xlog��
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

	// ���m�Ѽ�
	this->nowMovChess.x = 0;
	this->nowMovChess.y = 0;
	this->gamePlayer = !this->gamePlayer;	// �������a

	// ���ligalList
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
// �P�_�ӭt
bool GameManager::Win()
{
	// �p�G��ӡA�O�ogameover
	return true;
}
// �O�_�N�x
bool GameManager::WillWin()
{
	return true;
}

// ���ligalPos
std::vector<Pos> GameManager::GetLigalPos()
{
	return this->ligalPos;
}

// �]�wligalPos
void GameManager::SetLigalPos(std::vector<Pos> ligalPos)
{
	this->ligalPos = ligalPos;
}

// �����C��
void GameManager::GameOver()
{
	this->gameStart = false;
	this->file.close();
}

// ���s�}�l�C��
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

// Ū���C���O�_�}�l
bool GameManager::GetGameStart()
{
	return this->gameStart;
}

// �]�w�C���}�l
void GameManager::SetGameStart(bool in)
{
	this->gameStart = in;
}