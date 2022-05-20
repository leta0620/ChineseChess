#pragma once
#include "Chess6.h"

std::vector<Pos> Chess6::CanMove(Pos P, std::vector<std::vector<int>> Boardinfo) {
	std::vector<Pos> Position;
	if (Boardinfo[P.y][P.x]==1) {
		if (P.y <= 8 && (Boardinfo[P.y + 1][P.x] == 0 || (Boardinfo[P.y + 1][P.x] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x, P.y + 1);
			Position.push_back(tmp);
		}
		if (P.y >= 5 && P.x <= 7 && (Boardinfo[P.y][P.x + 1] == 0 || (Boardinfo[P.y][P.x + 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x+1, P.y );
			Position.push_back(tmp);
		}
		if (P.y >= 5 && P.x >= 1 && (Boardinfo[P.y][P.x - 1] == 0 || (Boardinfo[P.y][P.x - 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 1, P.y );
			Position.push_back(tmp);
		}
	}
	else {
		if (P.y >= 1 && (Boardinfo[P.y - 1][P.x] == 0 || (Boardinfo[P.y - 1][P.x] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x, P.y - 1);
			Position.push_back(tmp);
		}
		if (P.y <= 4 && P.x <= 7 && (Boardinfo[P.y][P.x + 1] == 0 || (Boardinfo[P.y][P.x + 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 1, P.y);
			Position.push_back(tmp);
		}
		if (P.y <= 4 && P.x >= 1 && (Boardinfo[P.y][P.x - 1] == 0 || (Boardinfo[P.y][P.x - 1] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 1, P.y);
			Position.push_back(tmp);
		}
	}
	return Position;
}