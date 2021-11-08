#include <stdlib.h>
#include <stdio.h>
#include "rules.h"
#include "accessible.h"
#include "interface.h"

int moving(int ** board, int i, int j, int x, int y)
{   
    if(x == 42)
        return 0;
    if(board[x][y] < 0){  // any cell which is not less than zero isn't free
        board[x][y]=board[i][j];
        board[i][j]=0;
        return 1;
    }
    else
    {
        printf("This cell can not be choosen!\n");
        return 0;
    }
} // Make pieces moving

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
} // Checking accessible cells

int moveCheck(int ** board, int team){
    return 0;
}

int chooseCell(int ** board, int pos1, int pos2)
{
    int pos3;
    char pos4;
    scanf("%i%c",&pos3,&pos4);
    printf("%i , %c\n",pos3,pos4);
    while (0 > pos3 || pos3 > 7 || 65 > pos4 || pos4 > 73)
        printf("Cell not in the board!\n");
    while(!moving(board,pos1,73-pos2,pos3,73-pos4)){ //moving in opposing dir
        printf("Cell not accessible!\n");
        printf("\033[0m On which cell do you want to move?\n");
        scanf("%i%c",&pos3,&pos4);
    }
    return 0;
} // Choosing where to move

int choosePiece(int ** board,int team)
{
    int pos1;
    char pos2;
    scanf("%i%c",&pos1,&pos2);
    while(0 > pos1 || pos1 > 7 || 65 > pos2 || pos2 > 73 ||
        board[pos1][73-pos2]/10 != team || board[pos1][73-pos2]==0 ||
        !move(board,pos1,73-pos2)){ // 0<pos1<7 and A<pos2<I
        printf("Wrong piece! or this piece can not move...\n");
        printf("Please enter another piece.\n");
        clearAcc(board);
        scanf("%i%c",&pos1,&pos2);
    }
    return pos1*100+pos2;
} // Choosing the piece to move


void turn(int ** board,int team)
{
    //int chk = check(board, team);
    clearAcc(board);
    printBoard(board);
    printf("%s it's your turn!\n", team ? "Red":"Blue");
    //if (chk)
      //  printf("Your King is in DANGER !");
    printf("\033[0m-_- Which piece do you want to move?\n");
    int pos1;
    char pos2;
    int ret = choosePiece(board,team);
    pos1 = ret/100;
    pos2 = ret%100;
    printf("%i , %c\n",pos1,pos2);
    printBoard(board);
    printf("\033[0m-_- On which cell do you want to move?\n");
    ret = chooseCell(board, pos1, pos2);
    clearAcc(board);
    printBoard(board);
    printf("It's enemy turn!\n");
} // Make a whole turn

void game(int ** board)
{
    printf("White always starts!\n");
    while(1)//!checkANDmat(board,1)) 
    {
        turn(board,1);
        if(0)//checkANDmat(board,0))
            break;
        turn(board,0);
    }
}

