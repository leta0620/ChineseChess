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

// �ХX�i���ʪ���m
bool GameManager::clickChess(Pos pos)
{
	// �]�m�ثe���ʪ���l�O���@���Ѥl
	this->nowMovChess = pos;

	// ��X�i���ʪ���m
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

// ���ʴѤl�A�ñN�t�@�誺�Ѥl�]���X�k�A�slog
void GameManager::moveChess(Pos pos)
{
	// ���ʴѤl
	boardGM.MovePos(this->nowMovChess, pos);

	// ��Xlog��
	file = new std::fstream(fileName, std::ios::app);
	std::string log;

	log += "Player: ";
	if (this->gamePlayer == true)
	{
		log += "1";
	}
	else if (this->gamePlayer == false)
	{
		log += "2";
	}
	log += ", Action: ";

	switch (boardGM.board[pos.y][pos.x]->GetName())
	{
	case 0:
		log += "General";
		break;
	case 1:
		log += "Advisor";
		break;
	case 2:
		log += "Elephant";
		break;
	case 3:
		log += "Chariot";
		break;
	case 4:
		log += "Horse";
		break;
	case 5:
		log += "Cannon";
		break;
	case 6:
		log += "Soldier";
		break;
	default:
		break;
	}

	log += " (";
	log += std::to_string(nowMovChess.x);
	log += ", ";
	log += std::to_string(nowMovChess.y);
	log += ") -> (";
	log += std::to_string(pos.x);
	log += ", ";
	log += std::to_string(pos.y);
	log += ")\n";

	file->write(log.c_str(), log.size());
	file->close();

	// ���m�Ѽ�
	this->nowMovChess.x = 0;
	this->nowMovChess.y = 0;
	this->gamePlayer = !this->gamePlayer;	// �������a

	// ���ligalList
	SetColorLegalPos(gamePlayer);

	return;
}

// �P�_�ӭt
int GameManager::Win()
{
	bool Red0 = false;
	bool black0 = false;

	// �M��ѽL�A�ݬO�_���N/�Ӧ��`
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
	{// ���Ӧ��A�¤��
		return 2;
	}
	else if (black0 == false)
	{// �±N���A�����
		return 1;
	}

	return 0;
}

// �O�_�N�x
int GameManager::WillWin()
{
	// �ˬd�L��
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			// �Y����m���Ѥl
			if (boardGM.board[y][x] != NULL)
			{
				if (boardGM.board[y][x]->GetColor() == !gamePlayer)
				{
					std::vector<Pos> legalPos;
					Pos tmp(x, y);
					legalPos = boardGM.CanMovePos(tmp);

					// �ˬd�i���ʪ���m���O�_�����N/��
					for (int check = 0; check < legalPos.size(); check++)
					{
						if (boardGM.board[legalPos[check].y][legalPos[check].x] != NULL)
						{
							if (boardGM.board[legalPos[check].y][legalPos[check].x]->GetName() == 0 && boardGM.board[legalPos[check].y][legalPos[check].x]->GetColor() == gamePlayer)
							{
								if (!gamePlayer == true)
								{
									// ����N�x
									return 1;
								}
								if (!gamePlayer == false)
								{
									// �¤�N�x
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


// ���legalPos
std::vector<Pos> GameManager::GetLegalPos()
{
	return this->legalPos;
}

// �]�wlegalPos
void GameManager::SetLegalPos(std::vector<Pos> legalPos)
{
	this->legalPos = legalPos;
}

// �����C��
void GameManager::GameOver()
{
	this->gameStart = false;
}

// ���s�}�l�C��
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

// �]�w�C���}�l
bool GameManager::GetGamePlayer()
{
	return gamePlayer;
}

// �]�w�ɮ�
void GameManager::SetFileName(std::string fileName)
{
	this->fileName = fileName;
}

// �]�w���a
void GameManager::SetGamePlayer(bool player)
{
	this->gamePlayer = player;
}

// �N�@���C�⪺�Ѥl�]���X�k
void GameManager::SetColorLegalPos(bool color)
{
	// ���ligalList
	std::vector<Pos> newLigalList;
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 9; x++)
		{
			if (boardGM.board[y][x] != NULL)
			{
				if (boardGM.board[y][x]->GetColor() == color)
				{
					newLigalList.push_back(boardGM.board[y][x]->GetPos());
				}
			}
		}
	}
	this->legalPos = newLigalList;
}