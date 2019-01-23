#include <stdlib.h>
#include <stdio.h>

void turn(int team)
{
    printf("\033[0m Which piece do you want to move?\n");
    int pos1;
    char pos2;
    scanf("%i%c",&pos1,&pos2);
    printf("%i , %c\n",pos1,pos2);
    if (0 > pos1 || pos1 > 7 || 65 > pos2 || pos2 > 73)
        printf("caca");
    else
    {
        //int cellsTab[8] = displayCells(x,y); //Should print list of available cells
        printf("\033[0m On which cell do you want to move?\n");
        scanf("%i%c",&pos1,&pos2);
        printf("%i , %c\n",pos1,pos2);
        if (0 > pos1 || pos1 > 7 || 65 > pos2 || pos2 > 73)
            printf("caca");
        int i = 0;
        LOOP:for(;i < 8; i++)
        {
            if (board[pos1][pos2-65] == cellsTab[i])
                moves(pos1,pos2-65);
        }
        if(i==8)
        {
            printf("You must select an availlable case !\n");
            goto LOOP;
        } 
    }                                            
}

