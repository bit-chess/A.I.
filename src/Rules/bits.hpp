#ifndef BITS_HPP
#define BITS_HPP

#include <bits/stdc++.h>

typedef struct{
    char chessBoard[8][8];
    
    int64_t board = 0L;
    int64_t white = 0L;
    int64_t black = 0L;

    int64_t pieceBoard[12];

    bool endOfGame = false;
    bool checkmateBlack = false;
    bool checkmateWhite = false;
    bool turn = true;

    int64_t lastMove[2];  
}Bits;

void buildBits(void);
void buildBits(char board_[8][8]);

#endif