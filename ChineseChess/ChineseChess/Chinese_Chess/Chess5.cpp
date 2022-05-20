#pragma once
#include "Chess5.h"

std::vector<Pos> Chess5::CanMove(Pos P, std::vector<std::vector<int>> Boardinfo) {
	std::vector<Pos> Position;
	int temp = 0;
	for (int i = P.x + 1; i <= 8; i++) {
		Pos tmp(i, P.y);
		if (Boardinfo[P.y][i] != 0 && temp == 1 && Boardinfo[P.y][i] != Boardinfo[P.y][P.x]) {
			Position.push_back(tmp);
			break;
		}
		if (Boardinfo[P.y][i] != 0) {
			temp++;
		}
		else if (Boardinfo[P.y][i] == 0 && temp == 0) {
			Position.push_back(tmp);
		}
	}
	temp = 0;
	for (int i = P.x - 1; i >= 0; i--) {
		Pos tmp(i, P.y);
		if (Boardinfo[P.y][i] != 0 && temp == 1 && Boardinfo[P.y][i] != Boardinfo[P.y][P.x]) {
			Position.push_back(tmp);
			break;
		}
		if (Boardinfo[P.y][i] != 0) {
			temp++;
		}
		else if (Boardinfo[P.y][i] == 0 && temp == 0) {
			Position.push_back(tmp);
		}
	}
	temp = 0;
	for (int i = P.y + 1; i <= 9; i++) {
		Pos tmp(P.x, i);
		if (Boardinfo[i][P.x] != 0 && temp == 1 && Boardinfo[i][P.x] != Boardinfo[P.y][P.x]) {
			Position.push_back(tmp);
			break;
		}
		if (Boardinfo[i][P.x] != 0) {
			temp++;
		}
		else if (Boardinfo[i][P.x] == 0 && temp == 0) {
			Position.push_back(tmp);
		}
	}
	temp = 0;
	for (int i = P.y - 1; i >= 0; i--) {
		Pos tmp(P.x, i);
		if (Boardinfo[i][P.x] != 0 && temp == 1 && Boardinfo[i][P.x] != Boardinfo[P.y][P.x]) {
			Position.push_back(tmp);
			break;
		}
		if (Boardinfo[i][P.x] != 0) {
			temp++;
		}
		else if (Boardinfo[i][P.x] == 0 && temp == 0) {
			Position.push_back(tmp);
		}
	}
	return Position;
}