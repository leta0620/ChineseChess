#pragma once
#include "Chess3.h"

std::vector<Pos> Chess3::CanMove(Pos P, std::vector<std::vector<int>> Boardinfo) {
	std::vector<Pos> Position;
	for (int i = P.x + 1; i <= 8; i++) {
		Pos tmp(i, P.y);
		if (Boardinfo[P.y][i] == 0) {
			Position.push_back(tmp);
		}
		else if (Boardinfo[P.y][i] != 0 && Boardinfo[P.y][i] != Boardinfo[P.y][P.x]) {
			Position.push_back(tmp);
			break;
		}
		else {
			break;
		}
	}
	for (int i = P.x - 1; i >= 0; i--) {
		Pos tmp(i, P.y);
		if (Boardinfo[P.y][i] == 0) {
			Position.push_back(tmp);
		}
		else if (Boardinfo[P.y][i] != 0 && Boardinfo[P.y][i] != Boardinfo[P.y][P.x]) {
			Position.push_back(tmp);
			break;
		}
		else {
			break;
		}
	}
	
	for (int i = P.y + 1; i <= 9; i++) {
		Pos tmp(P.x,i);
		if (Boardinfo[i][P.x] == 0) {
			Position.push_back(tmp);
		}
		else if (Boardinfo[i][P.x] != 0 && Boardinfo[i][P.x] != Boardinfo[P.y][P.x]) {
			Position.push_back(tmp);
			break;
		}
		else {
			break;
		}
	}
	for (int i = P.y - 1; i >= 0; i--) {
		Pos tmp(P.x, i);
		if (Boardinfo[i][P.x] == 0) {
			Position.push_back(tmp);
		}
		else if (Boardinfo[i][P.x] != 0 && Boardinfo[i][P.x] != Boardinfo[P.y][P.x]) {
			Position.push_back(tmp);
			break;
		}
		else {
			break;
		}
	}
	return Position;
}