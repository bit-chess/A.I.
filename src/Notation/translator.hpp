#ifndef TRANSLATOR_H
#define TRANSLATOR_H

const char letters[] = {'A','B','C','D','E', 'F', 'G', 'H'};
const int numbers[] = {8,7,6,5,4,3,2,1}; 

int NotationChessToComputer(char pos_w, int pos_h);
char *NotationComputerToChess(int i, int j);

#endif