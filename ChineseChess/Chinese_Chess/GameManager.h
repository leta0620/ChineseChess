#pragma once
#include <iostream>
#include "Board.h"

class GameManager
{
public:
	GameManager();

	// �ХX�i���ʪ���m
	Board clickChess(Pos);
	// ���ʴѤl�A�ñN�t�@�誺�Ѥl�]���X�k�A�slog
	Board moveChess(Pos);
	// �P�_�ӭt
	bool Win();
	// �O�_�N�x
	bool WillWin();

private:
	Board board;
	std::vector<Chess*> allChess;
	std::vector<Pos> ligalPos;
	// �ثe���b�ʧ@�����a�C��A0 >> red�A1 >> black
	int nowMoveColor = 0;
};