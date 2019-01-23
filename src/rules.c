#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void pawnMove(int ** board, int i, int j)
{
	if(board[i][j] == 1)
	{
		if(board[i][j+1] > 10 || board[i][j+1] < 1)
			board[i][j+1] = -1;
	}
}

void testin(int ** board)
{
	//pawnMove(board,1,2);
	board[2][3] = -1;
}


