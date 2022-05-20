#pragma once
#include "Chess1.h"

std::vector<Pos> Chess1::CanMove(Pos P, std::vector<std::vector<int>> Boardinfo) {
	std::vector<Pos> Position;
	if (Boardinfo[P.y][P.x] == 1) {
		if ((P.x <= 4 && P.y <= 1) && (Boardinfo[P.y + 1][P.x + 1] == 0 || (Boardinfo[P.y + 1][P.x + 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 1, P.y + 1);
			Position.push_back(tmp);
		}
		if ((P.x >= 4 && P.y <= 1) && (Boardinfo[P.y + 1][P.x - 1] == 0 || (Boardinfo[P.y + 1][P.x - 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 1, P.y + 1);
			Position.push_back(tmp);
		}
		if ((P.x <= 4 && P.y >= 1) && (Boardinfo[P.y - 1][P.x + 1] == 0 || (Boardinfo[P.y - 1][P.x + 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 1, P.y - 1);
			Position.push_back(tmp);
		}
		if ((P.x >= 4 && P.y >= 1) && (Boardinfo[P.y - 1][P.x - 1] == 0 || (Boardinfo[P.y - 1][P.x - 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 1, P.y - 1);
			Position.push_back(tmp);
		}
	}
	else {
		if ((P.x <= 4 && P.y <= 8) && (Boardinfo[P.y + 1][P.x + 1] == 0 || (Boardinfo[P.y + 1][P.x + 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 1, P.y + 1);
			Position.push_back(tmp);
		}
		if ((P.x >= 4 && P.y <= 8) && (Boardinfo[P.y + 1][P.x - 1] == 0 || (Boardinfo[P.y + 1][P.x - 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 1, P.y + 1);
			Position.push_back(tmp);
		}
		if ((P.x <= 4 && P.y >= 8) && (Boardinfo[P.y - 1][P.x + 1] == 0 || (Boardinfo[P.y - 1][P.x + 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 1, P.y - 1);
			Position.push_back(tmp);
		}
		if ((P.x >= 4 && P.y >= 8) && (Boardinfo[P.y - 1][P.x - 1] == 0 || (Boardinfo[P.y - 1][P.x - 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 1, P.y - 1);
			Position.push_back(tmp);
		}
	}
	return Position;
}