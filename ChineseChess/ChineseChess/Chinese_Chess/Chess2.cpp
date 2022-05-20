#pragma once
#include "Chess2.h"

std::vector<Pos> Chess2::CanMove(Pos P, std::vector<std::vector<int>> Boardinfo) {
	std::vector<Pos> Position;
	if (Boardinfo[P.y][P.x] == 1) {
		if ((P.x <= 6 && P.y <= 2) && (Boardinfo[P.y + 2][P.x + 2] == 0 || (Boardinfo[P.y + 2][P.x + 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 2, P.y + 2);
			if (Boardinfo[P.y + 1][P.x + 1] == 0) {
				Position.push_back(tmp);
			}
		}
		if ((P.x >= 2 && P.y <= 2) && (Boardinfo[P.y + 2][P.x - 2] == 0 || (Boardinfo[P.y + 2][P.x - 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 2, P.y + 2);
			if (Boardinfo[P.y + 1][P.x - 1] == 0) {
				Position.push_back(tmp);
			}
		}
		if ((P.x <= 6 && P.y >= 2) && (Boardinfo[P.y - 2][P.x + 2] == 0 || (Boardinfo[P.y - 2][P.x + 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 2, P.y - 2);
			if (Boardinfo[P.y - 1][P.x + 1] == 0) {
				Position.push_back(tmp);
			}
		}
		if ((P.x >= 2 && P.y >= 2) && (Boardinfo[P.y - 2][P.x - 2] == 0 || (Boardinfo[P.y - 2][P.x - 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 2, P.y - 2);
			if (Boardinfo[P.y - 1][P.x - 1] == 0) {
				Position.push_back(tmp);
			}
		}
	}
	else {
		if ((P.x <= 6 && P.y <= 7) && (Boardinfo[P.y + 2][P.x + 2] == 0 || (Boardinfo[P.y + 2][P.x + 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 2, P.y + 2);
			if (Boardinfo[P.y + 1][P.x + 1] == 0) {
				Position.push_back(tmp);
			}
		}
		if ((P.x >= 2 && P.y <= 7) && (Boardinfo[P.y + 2][P.x - 2] == 0 || (Boardinfo[P.y + 2][P.x - 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 2, P.y + 2);
			if (Boardinfo[P.y + 1][P.x - 1] == 0) {
				Position.push_back(tmp);
			}
		}
		if ((P.x <= 6 && P.y >= 7) && (Boardinfo[P.y - 2][P.x + 2] == 0 || (Boardinfo[P.y - 2][P.x + 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x + 2, P.y - 2);
			if (Boardinfo[P.y - 1][P.x + 1] == 0) {
				Position.push_back(tmp);
			}
		}
		if ((P.x >= 2 && P.y >= 7) && (Boardinfo[P.y - 2][P.x - 2] == 0 || (Boardinfo[P.y - 2][P.x - 2] != Boardinfo[P.y][P.x]))) {
			Pos tmp(P.x - 2, P.y - 2);
			if (Boardinfo[P.y - 1][P.x - 1] == 0) {
				Position.push_back(tmp);
			}
		}
	}
	return Position;
}