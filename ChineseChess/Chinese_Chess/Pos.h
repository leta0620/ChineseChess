#pragma once

// �y�Ъ���
class Pos
{
public:
	Pos();
	Pos(int x, int y);

	// ����==
	bool operator==(Pos& a);

	int x;
	int y;
};