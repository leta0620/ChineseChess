#pragma once
#include "Chess4.h"

std::vector<Pos> Chess4::CanMove(Pos P, std::vector<std::vector<int>> Boardinfo) {
	std::vector<Pos> Position;
	if (P.y <= 7 && Boardinfo[P.y + 1][P.x] == 0) {
		if (P.x >= 1 && (Boardinfo[P.y + 2][P.x - 1] == 0 || (Boardinfo[P.y + 2][P.x - 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 1, P.y + 2);
			Position.push_back(tmp);
		}
		if (P.x <= 7 && (Boardinfo[P.y + 2][P.x + 1] == 0 || (Boardinfo[P.y + 2][P.x + 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 1, P.y + 2);
			Position.push_back(tmp);
		}
	}
	if (P.y >= 2 && Boardinfo[P.y - 1][P.x] == 0) {
		if (P.x >= 1 && (Boardinfo[P.y - 2][P.x - 1] == 0 || (Boardinfo[P.y - 2][P.x - 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 1, P.y - 2);
			Position.push_back(tmp);
		}
		if (P.x <= 7 && (Boardinfo[P.y - 2][P.x + 1] == 0 || (Boardinfo[P.y - 2][P.x + 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 1, P.y - 2);
			Position.push_back(tmp);
		}
	}
	if (P.x <= 6 && Boardinfo[P.y][P.x + 1] == 0) {
		if (P.y >= 1 && (Boardinfo[P.y - 1][P.x + 2] == 0 || (Boardinfo[P.y - 1][P.x + 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 2, P.y - 1);
			Position.push_back(tmp);
		}
		if (P.y <= 8 && (Boardinfo[P.y + 1][P.x + 2] == 0 || (Boardinfo[P.y + 1][P.x + 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 2, P.y + 1);
			Position.push_back(tmp);
		}
	}
	if (P.x >= 2 && Boardinfo[P.y][P.x - 1] == 0) {
		if (P.y >= 1 && (Boardinfo[P.y - 1][P.x - 2] == 0 || (Boardinfo[P.y - 1][P.x - 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 2, P.y - 1);
			Position.push_back(tmp);
		}
		if (P.y <= 8 && (Boardinfo[P.y + 1][P.x - 2] == 0 || (Boardinfo[P.y + 1][P.x - 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 2, P.y + 1);
			Position.push_back(tmp);
		}
	}
	return Position;
}