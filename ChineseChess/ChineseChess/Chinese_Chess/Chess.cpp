#include "Chess.h"
void Chess::PreSet(int x, int y, bool Chesscolor) {
	pos.x = x;
	pos.y = y;
	color = Chesscolor;
}
void Chess::SetPos(Pos Chesspos) {
	pos = Chesspos;
}
void Chess::SetPos(int x, int y) {
	pos.x = x;
	pos.y = y;
}
Pos Chess::GetPos() {
	return pos;
}

bool Chess::GetColor() {
	return color;
}

int Chess::GetName() {
	return name;
}