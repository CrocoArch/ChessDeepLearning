#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

void pawnMove(int ** board, int i, int j, int team)
{
    int n = team == 1 ? 1 : -1;
	if(0<j+n && j+n<8 && (board[i][j+n]/10 != team || board[i][j+n] < 1))
    {
		board[i][j] = -1;
        board[i][j+n] = team*10+1;
	}
}

void rookMove(int ** board, int i, int j, int team){}

void horseMove(int ** board, int i ,int j, int team){}

void bishopMove(int ** board, int i ,int j, int team){}

void queenMove(int ** board, int i ,int j, int team){}

void kingMove(int ** board, int i ,int j, int team){}

void testin(int ** board)
{
	pawnMove(board,1,2,0);
	//board[2][3] = -1;
}

int move(int ** board, int i, int j)
{
    int piece = board[i][j];
    switch(piece%10){
        case 1:
            pawnMove(board,i,j,piece/10);
            return 0;
        case 2:
            rookMove(board,i,j,piece/10);
            return 0;
        case 3:
            horseMove(board,i,j,piece/10);
            return 0;
        case 4:
            bishopMove(board,i,j,piece/10);
            return 0;
        case 5:
            queenMove(board,i,j,piece/10);
            return 0;
        case 6:
            kingMove(board,i,j,piece/10);
            return 0;
    }
    return 0;
}
