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

	Pos GetPos();
	bool GetColor();
	int GetName();
	virtual std::vector<Pos> CanMove(Pos P, std::vector<std::vector<int>> Boardinfo)=0; // �i���ʦ�m
protected:
	Pos pos;	// ��m
	bool color = false; // ����true�A�¬�false
	int name = 0; // 0~6 �N�h�H��������
};