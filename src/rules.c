#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "moves.h"
#include "accessible.h"

int searchKing(int ** board, int team){
    int i,j;
    i = 0;
    j = 1;
    while(i<8 && board[i][j] != team*10+6){
        j = 1;
        while(j<8 && board[i][j] != team*10+6){
            j+=1;
        }
        i+=1;
    }
    return i*10+j;
}

int check(int ** board, int team){
    int pos = searchKing(board, team);
    printf("%s king is %i , %c", team ? "Red":"Blue",pos/10,73-pos%10);
    team = team ? 0:1;
    for(int i =0;i<8;i++){
        for(int j = 0;j<8; j++){
            if (board[i][j]/10 == team)
                move(board,i,j);
            if (board[pos/10][pos%10] < 0)
                return 1;
            clearAcc(board);
        }
    }
    return 0;
}

int * checkANDmat(int ** board, int team){
    int * val = calloc(8,sizeof(int));
    int index = 0;
    if(check(board,team)){
        int pos = searchKing(board,team);
        for(int i = -1;i<= 1;i++){
            for(int j = -1; j<= 1;j++){
                if(i != 0 && j!=0){
                    if(board[pos/10+i][pos%10+j]==0){
                        val[index]= pos+(i*10)+j;
                        index += 1;
                    }
                    else {
                        if(board[pos/10+i][pos%10+j]/10 != team){
                            
                            board[pos/10-i][pos%10+j] = 0;
                            team = team ? 0:1;
                            for(int i =0;i<8;i++){
                                for(int j = 0;j<8; j++){
                                    if (board[i][j]/10 == team)
                                        move(board,i,j);
                                }
                            }
                            if(board[pos/10][pos%10] >= 0)
                            {
                                val[index]= pos+(i*10)+j;
                                index += 1;
                            }
                        }
                    }
                }
            }
        }
        
        return val;
    }
    else
        return 0;
}

int pawnTrade(int ** board, int team, int i, int j){
    //TODO
    return 0;
}


