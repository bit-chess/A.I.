#ifndef BITS_HPP
#define BITS_HPP

#include <stdint.h>

typedef struct{
    char chessBoard[8][8];
    
    uint64_t board = 0L;
    uint64_t white = 0L;
    uint64_t black = 0L;

    uint64_t pieceBoard[12];

    bool endOfGame = false;
    bool checkmateBlack = false;
    bool checkmateWhite = false;
    bool turn = true;

    uint64_t lastMove[2];  
}Bits;

void buildBits(void);
void buildBits(char board_[8][8]);

#endif