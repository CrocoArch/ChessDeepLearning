#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <err.h>
#include "rules.h"

int main()
{
	printf("\033[42m coucou\n");
    int ** board = initBoard();
	testin(board);
	printBoard(board);
    return 0;
}
