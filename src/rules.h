#ifndef RULES_H
#define RULES_H

void pawnMove(int ** board, int i, int j, int team);

void rookMove(int ** board, int i, int j, int team);

void horseMove(int ** board, int i ,int j, int team);

void bishopMove(int ** board, int i ,int j, int team);

void queenMove(int ** board, int i ,int j, int team);

void kingMove(int ** board, int i ,int j, int team);

void testin(int ** board);

int move(int ** board, int i, int j);

#endif
