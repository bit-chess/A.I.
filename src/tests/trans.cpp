#include <bits/stdc++.h>
#include "../Notation/translator.hpp"
#include "../Algorithm/graph_builder.hpp"
#include "../Algorithm/alphabeta.hpp"
#include "../Rules/bits.hpp"
#include "../Rules/manipulator.hpp"

using namespace std;

int main(){
    Bits a;
    for(int i=0;i<8;i++)for(int j=0;j<8;j++)a.chessBoard[i][j] = 'i';
    AlphaBeta(a);
    Bits ans = getBits(0);    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%c", ans.chessBoard[i][j]);
        }
        printf("\n");
    }
    return 0;
}