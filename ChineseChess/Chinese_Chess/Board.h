#pragma once
#include <vector>
#include "Chess.h"

// �L����������
struct BoardItem
{
	// �O�_���X�k��m
	bool ligal = false;
	// �Ѥl�A�Y�L�Ѥl��0
	Chess* chess = 0;
};

class Board
{
public:
	// �w�]�غc�l
	Board();
	// �ǤJ�ثe���Ѥl�B�ݭn�ХܦX�k����m
	Board(std::vector<Chess*> allChess, std::vector<Pos> ligalPos);

private:
	// �L���ܼ�
	std::vector<std::vector<BoardItem>> board;
};