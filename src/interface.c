#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J")

//////////////////
//Board of chess//
//////////////////
int ** board;
//0 = available cell
//>0 = occuped cell
//<0 = accessible cell
//1 & 11 = white & black pawn
//2 & 11 = white & black rooks (Tour)
//3 & 13 = white & black knights (cavalier)
//4 & 14 = white & black bishop (fou)
//5 & 15 = white & black queens
//6 & 16 = white & black kings

void createBoard()
{
	board = malloc(9 * sizeof(int *)); //malloc the board
	for (size_t i = 0; i < 8; i++)
	{
		board[i] = malloc(9 * sizeof(int));
		for(size_t j = 0; j < 8; j++)
			board[i][j] = 0;						
	}
}

void init()
{
	createBoard();
	for(int i = 1; i < 9; i++)
	{
		board[1][i] = 1;
		board[6][i] = 11;
	}

	board[0][1] = 2;
	board[0][2] = 3;
	board[0][3] = 4;
	board[0][4] = 6;
	board[0][5] = 5;
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

}

char * pawn(int p)
{
	switch(p)
	{
		case -1:
			return ";42m   ";
		case 0:
			return "m   ";
		case 1:
			return ";34m P ";
		case 11:
			return ";31m P ";
		case 2:
			return ";34m R ";
		case 12:
			return ";31m R ";
		case 3:
			return ";34m C ";
		case 13:
			return ";31m C ";
		case 4:
			return ";34m B ";
		case 14:
			return ";31m B ";
		case 5:
			return ";34m Q ";
		case 15:
			return ";31m Q ";
		case 6:
			return ";34m K ";
		case 16:
			return ";31m K ";
	}

	return " ";
}


void printBoard()
{
	int cellcolor = 0;//0 = white & 1 = black
    char number = 49;
	for(int i=0;i<9;i++)
    {
		for(int j=0;j<9;j++)
        {
            if (j == 0 && i<8){
                printf(" %c ",number);
                number +=1;
            }

            else
            {
			    if (i == 8){
                    if(j == 0)
                        printf("   ");
                    else
                        printf(" %c ",73-j);
                }
                else
                {
                    char * c = pawn(board[i][j]);
			        if(cellcolor == 0)
				        printf("\033[47%s",c);
			        else
				        printf("\033[0%s",c); 
			        cellcolor = cellcolor == 0 ? 1 : 0;
                }
            }
		}
		
		printf("\033[0m\n");
		cellcolor = cellcolor == 0 ? 1 : 0;
	}
}

void displayBoard()
{
	init();
	clear();
	printBoard();
	free(board);
}
