#include "bits.hpp"
#include <string.h>

Bits our_game;
char initPosBlack[] = { 't', 'c', 'b', 'q', 'k', 'b', 'c', 't' };
char initPosWhite[] = { 'T', 'C', 'B', 'Q', 'K', 'B', 'C', 'T' };

void buildBits(void){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            our_game.chessBoard[i][j] = 'o';
        }
    }

    memset(our_game.chessBoard[1], 'p', sizeof(our_game.chessBoard[1]));
    memset(our_game.chessBoard[6], 'P', sizeof(our_game.chessBoard[6]));

    for(int i = 0; i < 8; i++) {
        our_game.chessBoard[1][i] = initPosBlack[i]; 
        our_game.chessBoard[6][i] = initPosWhite[i]; 
    }

    //chama manipulator
}
void buildBits(char board_[8][8]){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            our_game.chessBoard[i][j] = board_[i][j];
        }
    }
    //chama manipulator
}