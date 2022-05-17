#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Board.h"

// ����ɶ�
std::string GetTime();

class GameManager
{
public:
	GameManager();

	// �ХX�i���ʪ���m
	void clickChess(Pos);
	// ���ʴѤl�A�ñN�t�@�誺�Ѥl�]���X�k�A�slog
	void moveChess(Pos);
	// �P�_�ӭt
	bool Win();
	// �O�_�N�x
	bool WillWin();

	// ���ligalPos
	std::vector<Pos> GetLigalPos();

	// �]�wligalPos
	void SetLigalPos(std::vector<Pos> ligalPos);

	// �����C��
	void GameOver();

	// ���s�}�l�C��
	void ResetGame();

	// Ū���C���O�_�}�l
	bool GetGameStart();

	// �]�w�C���}�l
	void SetGameStart(bool in);

private:
	// �C���O�_�}�l
	bool gameStart;

	// �ŧi�L������
	Board boardGM;

	// �X�k���I����m
	std::vector<Pos> ligalPos;
	
	// �ثe���b���ʪ��Ѥl
	Pos nowMovChess;

	// log�ɪ��W��
	std::string fileName;
	
	// log ��
	std::ofstream file;

	// �C���i�����Ӷ��q�AgamePlayer = true�����A�Ϥ��C
	bool gamePlayer;
};