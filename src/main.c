#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <err.h>
#include "rules.h"
#include "accessible.h"
#include "moves.h"

int main()
{
    int ** board = initBoard();
	//testin(board);
	//int a = kingAcc(board, 3, 3, 0);
	printBoard(board);
    game(board);
    return 0;
}
