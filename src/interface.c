#include <stdio.h>
#include <stdlib.h>

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
	board = malloc(8 * sizeof(int *)); //malloc the board
	for (size_t i = 0; i < 8; i++)
	{
		board[i] = malloc(8 * sizeof(int));
		for(size_t j = 0; j < 8; j++)
			board[i][j] = 0;						
	}
}

void init()
{
	createBoard();
	for(int i = 0; i < 8; i++)
	{
		board[1][i] = 1;
		board[6][i] = 11;
	}

	board[0][0] = 2;
	board[0][1] = 3;
	board[0][2] = 4;
	board[0][3] = 6;
	board[0][4] = 5;
	board[0][5] = 4;
	board[0][6] = 3;
	board[0][7] = 2;
	board[7][0] = 2;
	board[7][1] = 3;
	board[7][2] = 4;
	board[7][3] = 5;
	board[7][4] = 6;
	board[7][5] = 4;
	board[7][6] = 3;
	board[7][7] = 2;

}

void printBoard()
{
	printf(" ");
	char c = 65;
	/*for(int i = 0; i < 8; i++)
	{
		printf(" %s ", c);
		c++;
	}*/
	
	for(int i=1;i<=8;i++)
        {
          for(int j=0;j<8;j++)
          {
             printf("\xDB");
             printf(" ");
           }
             printf("\n");
             if(i%2==0)
             {
                printf(" ");
             }
        }
printf("\033[031;43m This text is red with yellow background \033[0m This text has default color\n");
}

int main()
{
	init();
	printBoard();
	free(board);
}
