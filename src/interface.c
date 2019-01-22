#include <stdio.h>
#include <stdlib.h>

//////////////////
//Board of chess//
//////////////////
int ** board;
//0 = available cell
//>0 = occuped cell
//<0 = accessible cell

void init()
{
	board = malloc(8 * sizeof(int *)); //malloc the board
	for (size_t i = 0; i < 8; i++)
	{
		board[i] = malloc(8 * sizeof(int));
		for(size_t j = 0; j < 8; j++)
			board[i][j] = 0;						
	}
	


}
