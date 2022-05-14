#include "Board.h"

Board::Board()
{
	for (int y = 0; y < 9; y++)
	{	
		for (int x = 0; x < 10; x++)
		{
			BoardItem tmp;
			board[y].push_back(tmp);
		}
	}
}