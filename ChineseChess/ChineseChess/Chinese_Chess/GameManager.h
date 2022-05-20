#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include "Board.h"
#include "Viewer.h"

// ����ɶ�
std::string GetTime();

class GameManager
{
public:
	GameManager();

	//---------funtion-----------
	//
	// �ХX�i���ʪ���m
	bool clickChess(Pos);
	// ���ʴѤl�A�ñN�t�@�誺�Ѥl�]���X�k�A�slog
	void moveChess(Pos);

	// �P�_�ӭt
	int Win();
	// �O�_�N�x
	int WillWin();
	// ���legalPos
	std::vector<Pos> GetLegalPos();
	// �]�wlegalPos
	void SetLegalPos(std::vector<Pos> legalPos);
	// �����C��
	void GameOver();
	// ���s�}�l�C��
	void ResetGame();
	// Ū���C���O�_�}�l
	bool GetGameStart();
	// �]�w�C���}�l
	void SetGameStart(bool in);
	// Ū���ɮסA���L��
	void LoadLog();



	//-----------����---------------
	// 
	// Viewer����
	Viewer viewer;	
	// �ŧi�L������
	Board boardGM;
private:
	// �C���O�_�}�l
	bool gameStart;

	// �X�k���I����m
	std::vector<Pos> legalPos;
	
	// �ثe���b���ʪ��Ѥl
	Pos nowMovChess;

	// log�ɪ��W��
	std::string fileName;
	
	// log ��
	std::ofstream file;

	// �C���i�����Ӷ��q�AgamePlayer = true�����A�Ϥ��C
	bool gamePlayer;
};