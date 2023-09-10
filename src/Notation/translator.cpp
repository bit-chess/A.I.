#include <stdio.h>
#include <stdlib.h>
#include "translator.hpp"

int NotationChessToComputer(char pos_w, int pos_h){
    int i = 7 - (pos_h - 1);
    int j = 0;
    if (pos_w >= 'A' && pos_w <= 'Z') {
        j = pos_w - 'A';
    }
    else if(pos_w >= 'a' && pos_w <= 'z') {
        j = pos_w - 'a';
    }else {
        printf("Argumento Inválido!");
        return -1;
    }
    return (i*8 + j);
}
char *NotationComputerToChess(int i, int j){
    char *ans = (char *) malloc(2);
    sprintf(ans, "%c%d", letters[j], numbers[i]);
    return ans;
}