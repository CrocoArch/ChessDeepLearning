#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J")

//////////////////
//Board of chess//
//////////////////
//0 = available cell
//>0 = occuped cell
//<0 = accessible cell
//1 & 11 = white & black pawn
//2 & 11 = white & black rooks (Tour)
//3 & 13 = white & black knights (cavalier)
//4 & 14 = white & black bishop (fou)
//5 & 15 = white & black queens
//6 & 16 = white & black kings

int ** createBoard()
{
	int ** board = malloc(9 * sizeof(int *)); //malloc the board
	for (size_t i = 0; i < 8; i++)
	{
		board[i] = malloc(9 * sizeof(int));
		for(size_t j = 0; j < 8; j++)
			board[i][j] = 0;						
	}
	return board;
}

int **  init()
{
	int ** board = createBoard();
	for(int i = 1; i < 9; i++)
	{
		board[1][i] = 1;
		board[6][i] = 11;
	}

	board[0][1] = 2;
	board[0][2] = 3;
	board[0][3] = 4;
	board[0][4] = 5;
	board[0][5] = 6;
	board[0][6] = 4;
	board[0][7] = 3;
	board[0][8] = 2;
	board[7][1] = 12;
	board[7][2] = 13;
	board[7][3] = 14;
	board[7][4] = 15;
	board[7][5] = 16;
	board[7][6] = 14;
	board[7][7] = 13;
	board[7][8] = 12;

	return board;

}

char * pawn(int p)
{
	switch(p)
	{
		case 20:
			return "m       ";
		case 0:
			return "m       ";
		case 1:
			return ";34m Pawn  ";
		case 11:
			return ";31m Pawn  ";
		case 2:
			return ";34m Rook  ";
		case 12:
			return ";31m Rook  ";
		case 3:
			return ";34m Horse ";
		case 13:
			return ";31m Horse ";
		case 4:
			return ";34m Bishop";
		case 14:
			return ";31m Bishop";
		case 5:
			return ";34m Queen ";
		case 15:
			return ";31m Queen ";
		case 6:
			return ";34m  King ";
		case 16:
			return ";31m  King ";
	}

	return " ";
}

char * backColor(int p)
{
	if(p < 0)
		return "42;";
	if(p < 10)
		return "";
    else
        return "cacaBackColor";
}


void printBoard(int ** board)
{
	clear();
	int cellcolor = 0;//0 = white & 1 = black
	printf("\033[0m          H      G      F      E      D      C      B      A \n");
	for(int i=0;i<8;i++)
    {
		for(int k=0;k<3;k++)
        {
			for(int j = 0; j < 9; j++) //line per case
			{
				if(j == 0)
				{
					if(k == 1)
						printf("\033[0m   %d   ",i);
					else
						printf("\033[0m       ");
				}
				else
				{
					if(k == 1)
					{
						char * c = board[i][j] >= 0 ? pawn(board[i][j]) :
							pawn(-board[i][j]);
						if(board[i][j] == -20)
							printf("\033[42%s",c);
						else
						{
							if(board[i][j] < 0)  //mettre du rouge ici
								printf("\033[43%s",c);
							else
							{
								if(cellcolor == 0)
									printf("\033[47%s",c);
								else
									printf("\033[0%s",c); 
						}

						}
						cellcolor = cellcolor == 0 ? 1 : 0;
					}
					else
					{
						if(board[i][j] < 0)
						{	
							if(board[i][j] == -20)
								printf("\033[42m       ");
							else
								printf("\033[43m       ");
						}
						else
						{
							if(cellcolor == 0)
								printf("\033[47m       ");
							else
								printf("\033[0m       ");
						}

					cellcolor = cellcolor == 0 ? 1 : 0;
					}
				}

			}
			printf("\n");

		}	
	//	printf("\033[0m\n");
		cellcolor = cellcolor == 0 ? 1 : 0;
	}
	printf("\033[0m\n");
	printf("\033[0m\n");
}


int ** initBoard()
{
	int ** board = init();
	clear();
	printBoard(board);
	return board;
	//free(board);
}
