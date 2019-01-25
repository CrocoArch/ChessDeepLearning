#include <stdlib.h>
#include <stdio.h>
#include "rules.h"
#include "accessible.h"
#include "interface.h"

int moving(int ** board, int i, int j, int x, int y)
{       
    if(board[x][y] < 0){
        board[x][y]=board[i][j];
        board[i][j]=0;
        return 1;
    }
    else
    {
        printf("This cell can not be choosen!\n");
        return 0;
    }
}

int move(int ** board, int i, int j)
{
    int piece = board[i][j];
        switch(piece%10){
            case 1:
                return pawnAcc(board,i,j,piece/10);
            case 2:
                return rookAcc(board,i,j,piece/10);
            case 3:
                return horseAcc(board,i,j,piece/10);
            case 4:
                return bishopAcc(board,i,j,piece/10);
            case 5:
                return queenAcc(board,i,j,piece/10);
            case 6:
                return kingAcc(board,i,j,piece/10);
            }
    return 0;
}

int moveCheck(int ** board, int team){
    return 0;
}

void turn(int ** board,int team)
{
    printf("%s it's your turn!", team ? "Red":"Blue");
    if(check(board,team))
        moveCheck(board,team);
    else
    {
        //clearAcc(board);
        printf("\033[0m Which piece do you want to move?\n");
        int pos1,pos3;
        char pos2,pos4;
        scanf("%i%c",&pos1,&pos2);
        while(0 > pos1 || pos1 > 7 || 65 > pos2 || pos2 > 73 ||
                            board[pos1][73-pos2]/10 != team ){
            printf("Wrong piece!\n");
            printf("Please enter another piece.\n");
            scanf("%i%c",&pos1,&pos2);
        }
        printf("%i , %c\n",pos1,pos2);
        move(board,pos1,73-pos2);
        printBoard(board);
        printf("\033[0m On which cell do you want to move?\n");
        scanf("%i%c",&pos3,&pos4);
        printf("%i , %c\n",pos3,pos4);
        while (0 > pos1 || pos1 > 7 || 65 > pos2 || pos2 > 73)
            printf("Cell not in the board!\n");
        while(!moving(board,pos1,73-pos2,pos3,73-pos4)){
            printf("Cell not accessible!\n");
            printf("\033[0m On which cell do you want to move?\n");
            scanf("%i%c",&pos3,&pos4);
        }
        clearAcc(board);
        printBoard(board);
        printf("It's enemy turn!\n");
    }
}

void game(int ** board)
{
    printf("White always starts!\n");
    while(!checkANDmat(board,1)) 
    {
        turn(board,1);
        if(checkANDmat(board,0))
            break;
        turn(board,0);
    }
}

