#include "Board.h"

Board::Board()
{
	board.resize(10);
	for (int y = 0; y < 10; y++)
	{
		board[y].resize(9);
	}
	AllSet();
}
void Board::AllSet() {
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			board[i][j] = NULL;
		}
	}
	board[0][0] = &B3_0;
	board[0][1] = &B4_0;
	board[0][2] = &B2_0;
	board[0][3] = &B1_0;
	board[0][4] = &B0;
	board[0][5] = &B1_1;
	board[0][6] = &B2_1;
	board[0][7] = &B4_1;
	board[0][8] = &B3_1;
	board[2][1] = &B5_0;
	board[2][7] = &B5_1;
	board[3][0] = &B6_0;
	board[3][2] = &B6_1;
	board[3][4] = &B6_2;
	board[3][6] = &B6_3;
	board[3][8] = &B6_4;
	B3_0.PreSet(0, 0, false);
	B4_0.PreSet(1, 0, false);
	B2_0.PreSet(2, 0, false);
	B1_0.PreSet(3, 0, false);
	B0.PreSet(4, 0, false);
	B1_1.PreSet(5, 0, false);
	B2_1.PreSet(6, 0, false);
	B4_1.PreSet(7, 0, false);
	B3_1.PreSet(8, 0, false);
	B5_0.PreSet(1, 2, false);
	B5_1.PreSet(7, 2, false);
	B6_0.PreSet(0, 3, false);
	B6_1.PreSet(2, 3, false);
	B6_2.PreSet(4, 3, false);
	B6_3.PreSet(6, 3, false);
	B6_4.PreSet(8, 3, false);

	board[9][0] = &R3_0;
	board[9][1] = &R4_0;
	board[9][2] = &R2_0;
	board[9][3] = &R1_0;
	board[9][4] = &R0;
	board[9][5] = &R1_1;
	board[9][6] = &R2_1;
	board[9][7] = &R4_1;
	board[9][8] = &R3_1;
	board[7][1] = &R5_0;
	board[7][7] = &R5_1;
	board[6][0] = &R6_0;
	board[6][2] = &R6_1;
	board[6][4] = &R6_2;
	board[6][6] = &R6_3;
	board[6][8] = &R6_4;
	R3_0.PreSet(0, 9, true);
	R4_0.PreSet(1, 9, true);
	R2_0.PreSet(2, 9, true);
	R1_0.PreSet(3, 9, true);
	R0.PreSet(4, 9, true);
	R1_1.PreSet(5, 9, true);
	R2_1.PreSet(6, 9, true);
	R4_1.PreSet(7, 9, true);
	R3_1.PreSet(8, 9, true);
	R5_0.PreSet(1, 7, true);
	R5_1.PreSet(7, 7, true);
	R6_0.PreSet(0, 6, true);
	R6_1.PreSet(2, 6, true);
	R6_2.PreSet(4, 6, true);
	R6_3.PreSet(6, 6, true);
	R6_4.PreSet(8, 6, true);
}
std::vector<Pos> Board::CanMovePos(Pos P) {
	std::vector<Pos> Position;
	Pos tmp = P;
	int temp;
	switch (board[P.y][P.x]->GetName()) {
	case 0:
		if (P.x <= 4 && (board[P.y][P.x + 1] == NULL || (board[P.y][P.x + 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
			tmp.x = P.x + 1;
			Position.push_back(tmp);
		}
		if (P.x >= 4 && (board[P.y][P.x - 1] == NULL || (board[P.y][P.x - 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
			tmp.x = P.x - 1;
			Position.push_back(tmp);
		}
		tmp = P;
		if (!board[P.y][P.x]->GetColor()) {
			if (P.y <= 1 && (board[P.y + 1][P.x] == NULL || (board[P.y + 1][P.x]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.y = P.y + 1;
				Position.push_back(tmp);
			}
			if (P.y >= 1 && (board[P.y - 1][P.x] == NULL || (board[P.y - 1][P.x]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.y = P.y - 1;
				Position.push_back(tmp);
			}
			tmp = P;
			for (int i = P.y + 1; i <= 9; i++) {
				if (board[i][P.x] != NULL && board[i][P.x]->GetName() == 0) {
					tmp.y = i;
					Position.push_back(tmp);
				}
				else if (board[i][P.x] != NULL) {
					break;
				}
			}
		}
		else {
			if (P.y <= 8 && (board[P.y + 1][P.x] == NULL || (board[P.y + 1][P.x]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.y = P.y + 1;
				Position.push_back(tmp);
			}
			if (P.y >= 8 && (board[P.y - 1][P.x] == NULL || (board[P.y - 1][P.x]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.y = P.y - 1;
				Position.push_back(tmp);
			}
			tmp = P;
			for (int i = P.y; i >= 0; i--) {
				if (board[i][P.x] != NULL && board[i][P.x]->GetName() == 0) {
					tmp.y = i;
					Position.push_back(tmp);
				}
				else if (board[i][P.x] != NULL) {
					break;
				}
			}
		}
		break;
	case 1:
		if (!board[P.y][P.x]->GetColor()) {
			if ((P.x <= 4 && P.y <= 1) && (board[P.y + 1][P.x + 1] == NULL || (board[P.y + 1][P.x + 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp = P;
				tmp.x += 1;
				tmp.y += 1;
				Position.push_back(tmp);
			}
			if ((P.x >= 4 && P.y <= 1) && (board[P.y + 1][P.x - 1] == NULL || (board[P.y + 1][P.x - 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp = P;
				tmp.x -= 1;
				tmp.y += 1;
				Position.push_back(tmp);
			}
			if ((P.x <= 4 && P.y >= 1) && (board[P.y - 1][P.x + 1] == NULL || (board[P.y - 1][P.x + 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp = P;
				tmp.x += 1;
				tmp.y -= 1;
				Position.push_back(tmp);
			}
			if ((P.x >= 4 && P.y >= 1) && (board[P.y - 1][P.x - 1] == NULL || (board[P.y - 1][P.x - 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp = P;
				tmp.x -= 1;
				tmp.y -= 1;
				Position.push_back(tmp);
			}
		}
		else {
			if ((P.x <= 4 && P.y <= 8) && (board[P.y + 1][P.x + 1] == NULL || (board[P.y + 1][P.x + 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp = P;
				tmp.x += 1;
				tmp.y += 1;
				Position.push_back(tmp);
			}
			if ((P.x >= 4 && P.y <= 8) && (board[P.y + 1][P.x - 1] == NULL || (board[P.y + 1][P.x - 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp = P;
				tmp.x -= 1;
				tmp.y += 1;
				Position.push_back(tmp);
			}
			if ((P.x <= 4 && P.y >= 8) && (board[P.y - 1][P.x + 1] == NULL || (board[P.y - 1][P.x + 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp = P;
				tmp.x += 1;
				tmp.y -= 1;
				Position.push_back(tmp);
			}
			if ((P.x >= 4 && P.y >= 8) && (board[P.y - 1][P.x - 1] == NULL || (board[P.y - 1][P.x - 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp = P;
				tmp.x -= 1;
				tmp.y -= 1;
				Position.push_back(tmp);
			}
		}
		break;
	case 2:
		if (!board[P.y][P.x]->GetColor()) {
			tmp = P;
			if ((P.x <= 6 && P.y <= 2) && (board[P.y + 2][P.x + 2] == NULL || (board[P.y + 2][P.x + 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x += 2;
				tmp.y += 2;
				if (board[P.y + 1][P.x + 1] == NULL) {
					Position.push_back(tmp);
				}
			}
			tmp = P;
			if ((P.x >= 2 && P.y <= 2) && (board[P.y + 2][P.x - 2] == NULL || (board[P.y + 2][P.x - 2]->GetColor() != board[P.y][P.x]->GetColor()))) {

				tmp.x -= 2;
				tmp.y += 2;
				if (board[P.y + 1][P.x - 1] == NULL) {
					Position.push_back(tmp);
				}
			}
			tmp = P;
			if ((P.x <= 6 && P.y >= 2) && (board[P.y - 2][P.x + 2] == NULL || (board[P.y - 2][P.x + 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x += 2;
				tmp.y -= 2;
				if (board[P.y - 1][P.x + 1] == NULL) {
					Position.push_back(tmp);
				}
			}
			tmp = P;
			if ((P.x >= 2 && P.y >= 2) && (board[P.y - 2][P.x - 2] == NULL || (board[P.y - 2][P.x - 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x -= 2;
				tmp.y -= 2;
				if (board[P.y - 1][P.x - 1] == NULL) {
					Position.push_back(tmp);
				}
			}
		}
		else {
			tmp = P;
			if ((P.x <= 6 && P.y <= 7) && (board[P.y + 2][P.x + 2] == NULL || (board[P.y + 2][P.x + 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x += 2;
				tmp.y += 2;
				if (board[P.y + 1][P.x + 1] == NULL) {
					Position.push_back(tmp);
				}
			}
			tmp = P;
			if ((P.x >= 2 && P.y <= 7) && (board[P.y + 2][P.x - 2] == NULL || (board[P.y + 2][P.x - 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x -= 2;
				tmp.y += 2;
				if (board[P.y + 1][P.x - 1] == NULL) {
					Position.push_back(tmp);
				}
			}
			tmp = P;
			if ((P.x <= 6 && P.y >= 7) && (board[P.y - 2][P.x + 2] == NULL || (board[P.y - 2][P.x + 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x += 2;
				tmp.y -= 2;
				if (board[P.y - 1][P.x + 1] == NULL) {
					Position.push_back(tmp);
				}
			}
			tmp = P;
			if ((P.x >= 2 && P.y >= 7) && (board[P.y - 2][P.x - 2] == NULL || (board[P.y - 2][P.x - 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x -= 2;
				tmp.y -= 2;
				if (board[P.y - 1][P.x - 1] == NULL) {
					Position.push_back(tmp);
				}

			}
		}
		break;
	case 3:
		tmp = P;
		for (int i = P.x + 1; i <= 8; i++) {
			tmp.x = i;
			if (board[P.y][i] == NULL) {
				Position.push_back(tmp);
			}
			else if (board[P.y][i] != NULL && board[P.y][i]->GetColor() != board[P.y][P.x]->GetColor()) {
				Position.push_back(tmp);
				break;
			}
			else {
				break;
			}
		}
		for (int i = P.x - 1; i >= 0; i--) {
			tmp.x = i;
			if (board[P.y][i] == NULL) {
				Position.push_back(tmp);
			}
			else if (board[P.y][i] != NULL && board[P.y][i]->GetColor() != board[P.y][P.x]->GetColor()) {
				Position.push_back(tmp);
				break;
			}
			else {
				break;
			}
		}
		tmp = P;
		for (int i = P.y + 1; i <= 9; i++) {
			tmp.y = i;
			if (board[i][P.x] == NULL) {
				Position.push_back(tmp);
			}
			else if (board[i][P.x] != NULL && board[i][P.x]->GetColor() != board[P.y][P.x]->GetColor()) {
				Position.push_back(tmp);
				break;
			}
			else {
				break;
			}
		}
		for (int i = P.y - 1; i >= 0; i--) {
			tmp.y = i;
			if (board[i][P.x] == NULL) {
				Position.push_back(tmp);
			}
			else if (board[i][P.x] != NULL && board[i][P.x]->GetColor() != board[P.y][P.x]->GetColor()) {
				Position.push_back(tmp);
				break;
			}
			else {
				break;
			}
		}
		break;
	case 4:
		if (P.y <= 7 && board[P.y + 1][P.x] == NULL) {
			tmp = P;
			if (P.x >= 1 && (board[P.y + 2][P.x - 1] == NULL || (board[P.y + 2][P.x - 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp = P;
				tmp.x = P.x - 1;
				tmp.y = P.y + 2;
				Position.push_back(tmp);
			}
			tmp = P;
			if (P.x <= 7 && (board[P.y + 2][P.x + 1] == NULL || (board[P.y + 2][P.x + 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x = P.x + 1;
				tmp.y = P.y + 2;
				Position.push_back(tmp);
			}
		}
		if (P.y >= 2 && board[P.y - 1][P.x] == NULL) {
			tmp = P;
			if (P.x >= 1 && (board[P.y - 2][P.x - 1] == NULL || (board[P.y - 2][P.x - 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x = P.x - 1;
				tmp.y = P.y - 2;
				Position.push_back(tmp);
			}
			tmp = P;
			if (P.x <= 7 && (board[P.y - 2][P.x + 1] == NULL || (board[P.y - 2][P.x + 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x = P.x + 1;
				tmp.y = P.y - 2;
				Position.push_back(tmp);
			}
		}
		if (P.x <= 6 && board[P.y][P.x + 1] == NULL) {
			tmp = P;
			if (P.y >= 1 && (board[P.y - 1][P.x + 2] == NULL || (board[P.y - 1][P.x + 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x = P.x + 2;
				tmp.y = P.y - 1;
				Position.push_back(tmp);
			}
			tmp = P;
			if (P.y <= 8 && (board[P.y + 1][P.x + 2] == NULL || (board[P.y + 1][P.x + 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x = P.x + 2;
				tmp.y = P.y + 1;
				Position.push_back(tmp);
			}
		}
		if (P.x >= 2 && board[P.y][P.x - 1] == NULL) {
			tmp = P;
			if (P.y >= 1 && (board[P.y - 1][P.x - 2] == NULL || (board[P.y - 1][P.x - 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x = P.x - 2;
				tmp.y = P.y - 1;
				Position.push_back(tmp);
			}
			if (P.y <= 8 && (board[P.y + 1][P.x - 2] == NULL || (board[P.y + 1][P.x - 2]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x = P.x + 2;
				tmp.y = P.y - 1;
				Position.push_back(tmp);
			}
		}
		break;
	case 5:
		tmp = P;
		temp = 0;
		for (int i = P.x + 1; i <= 8; i++) {
			if (board[P.y][i] != NULL && temp == 1 && board[P.y][i]->GetColor() != board[P.y][P.x]->GetColor()) {
				tmp.x = i;
				Position.push_back(tmp);
				break;
			}
			if (board[P.y][i] != NULL) {
				temp++;
			}
			else if (board[P.y][i] == NULL && temp == 0) {
				tmp.x = i;
				Position.push_back(tmp);
			}
		}
		temp = 0;
		for (int i = P.x - 1; i >= 0; i--) {
			if (board[P.y][i] != NULL && temp == 1 && board[P.y][i]->GetColor() != board[P.y][P.x]->GetColor()) {
				tmp.x = i;
				Position.push_back(tmp);
				break;
			}
			if (board[P.y][i] != NULL) {
				temp++;
			}
			else if (board[P.y][i] == NULL && temp == 0) {
				tmp.x = i;
				Position.push_back(tmp);
			}
		}
		tmp = P;
		temp = 0;
		for (int i = P.y + 1; i <= 9; i++) {
			if (board[i][P.x] != NULL && temp == 1 && board[i][P.x]->GetColor() != board[P.y][P.x]->GetColor()) {
				tmp.y = i;
				Position.push_back(tmp);
				break;
			}
			if (board[i][P.x] != NULL) {
				temp++;
			}
			else if (board[i][P.x] == NULL && temp == 0) {
				tmp.y = i;
				Position.push_back(tmp);
			}
		}
		temp = 0;
		for (int i = P.y - 1; i >= 0; i--) {
			if (board[i][P.x] != NULL && temp == 1 && board[i][P.x]->GetColor() != board[P.y][P.x]->GetColor()) {
				tmp.y = i;
				Position.push_back(tmp);
				break;
			}
			if (board[i][P.x] != NULL) {
				temp++;
			}
			else if (board[i][P.x] == NULL && temp == 0) {
				tmp.y = i;
				Position.push_back(tmp);
			}
		}
		break;
	case 6:
		if (!board[P.y][P.x]->GetColor()) {
			if (P.y <= 8 && (board[P.y + 1][P.x] == NULL || (board[P.y + 1][P.x]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.y += 1;
				Position.push_back(tmp);
			}
			tmp = P;
			if (P.y >= 5 && P.x <= 7 && (board[P.y][P.x + 1] == NULL || (board[P.y][P.x + 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x += 1;
				Position.push_back(tmp);
			}
			tmp = P;
			if (P.y >= 5 && P.x >= 1 && (board[P.y][P.x - 1] == NULL || (board[P.y][P.x - 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x -= 1;
				Position.push_back(tmp);
			}
		}
		else {
			tmp = P;
			if (P.y >= 1 && (board[P.y - 1][P.x] == NULL || (board[P.y - 1][P.x]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.y -= 1;
				Position.push_back(tmp);
			}
			tmp = P;
			if (P.y <= 4 && P.x <= 7 && (board[P.y][P.x + 1] == NULL || (board[P.y][P.x + 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x += 1;
				Position.push_back(tmp);
			}
			tmp = P;
			if (P.y <= 4 && P.x >= 1 && (board[P.y][P.x - 1] == NULL || (board[P.y][P.x - 1]->GetColor() != board[P.y][P.x]->GetColor()))) {
				tmp.x -= 1;
				Position.push_back(tmp);
			}
		}
		break;
	}
	return Position;
}
void Board::MovePos(Pos PosFirst, Pos PosSecond) {
	Chess* temp;
	board[PosFirst.y][PosFirst.x]->SetPos(PosSecond);
	temp = board[PosFirst.y][PosFirst.x];
	board[PosSecond.y][PosSecond.x] = temp;
	board[PosFirst.y][PosFirst.x] = NULL;

}