#pragma once
#include "Pos.h"
#include <vector>

// �Ѥl�����O
class Chess
{
public:
	void PreSet(int x, int y, bool Chesscolor);
	void SetPos(Pos);
	void SetPos(int x, int y);
	void Setalive(bool);

	Pos GetPos();
	bool GetColor();
	int GetName();
	bool Getalive();
	
protected:
	Pos pos;	// ��m
	bool color = false; // ����true�A�¬�false
	int name = 0; // 0~6 �N�h�H��������
	bool alive = true;
};