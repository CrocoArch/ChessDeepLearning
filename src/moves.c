#include <stdlib.h>
#include <stdio.h>
#include "rules.h"
#include "accessible.h"

int moving(int ** board, int i, int j, int x, int y)
{       
    if(board[i][j] < 0){
        board[x][y]=board[i][j];
        board[i][j]=0;
        return 1;
    }
    else
    {
        wrongCell();
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

int moveCheck(int ** board, int board){}

void turn(int ** board,int team)
{
    printf("%s it's your turn!", team ? "Red":"Blue");
    if(check(board,team))
        moveCheck(board,team);
    else
    {
        printf("\033[0m Which piece do you want to move?\n");
        int pos1,pos3;
        char pos2,pos4;
        scanf("%i%c",&pos1,&pos2);
        printf("%i , %c\n",pos1,pos2);
        if (0 > pos1 || pos1 > 7 || 65 > pos2 || pos2 > 73)
            printf("caca");
        else
        {
            move(board,pos1,72-pos2);
            printf("\033[0m On which cell do you want to move?\n");
            scanf("%i%c",&pos3,&pos4);
            printf("%i , %c\n",pos3,pos4);
            if (0 > pos1 || pos1 > 7 || 65 > pos2 || pos2 > 73)
                printf("Cell not in the board!\n");
            while(!moving(board,pos1,72-pos2,pos3,72-pos4)){
                printf("Cell not accessible!\n");
                printf("\033[0m On which cell do you want to move?\n");
                scanf("%i%c",&pos3,&pos4);
            }   
            printf("It's enemy turn!\n");
        }
    }
}

void game(int ** board)
{
    printf("White always starts!\n");
    while(!check&mat(board,1)) 
    {
        turn(board,1);
        if(check&mat(board,0))
            break;
        turn(board,0);
    }
}

