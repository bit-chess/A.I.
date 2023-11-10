#include "alphabeta.hpp"
#include "graph_builder.hpp"
#include "../Rules/bits.hpp"
#include <stddef.h>

typedef u64 uint64_t;

using namespace std;

double max(double x, double y) {
    if(x >= y) return x;
    else return y; 
}

void AlphaBeta(Bits bit){
    createGraph(bit);
}

double algorithm(int node, int depth, double a, double b, bool isMaximizing){
    if(!depth) {
        double e = Evaluate(getBits(node));
        setWeight(node, e);
        removeBit(node);
        return e;
    }

    else if (isMaximizing) {
        double value = -inf;
        Bits p = getbits(node);
        u64 x[64];
        x = uncheckedMoves(p);
        bool flag = true;
        for(int sq = 0; sq <64 && flag; sq++) {
            while(x[sq] != 0ULL && flag) {
                int pos = lsb(x[sq]);
                Bits tmp = p;
                changePos(sq, pos, tmp);
                tmp.turn = !tmp.turn;
                if(!isCheckWhite(tmp)) {
                    createGraph(node, tmp);
                    value = max(value, algorithm((getCountNodes() - 1), (depth-1), a, b, false));
                    a = max(a, value);
                }
                x[sq] = reset(x[sq]);
                if(a >= b) flag = false;
            }
        }

        removeBitIf(node);
        setWeight(node, value);
        return value; 
    }

    else {
        double value = inf;
        Bits p = getbits(node);
        u64 x[64];
        x = uncheckedMoves(p);
        bool flag = true;
        for(int sq = 0; sq <64 && flag; sq++) {
            while(x[sq] != 0ULL && flag) {
                int pos = lsb(x[sq]);
                Bits tmp = p;
                changePos(sq, pos, tmp);
                tmp.turn = !tmp.turn;
                if(!isCheckBlack(tmp)) {
                    createGraph(node, tmp);
                    value = min(value, algorithm((getCountNodes() - 1), (depth-1), a, b, false));
                    b = min(b, value);
                }
                x[sq] = reset(x[sq]);
                if(a >= b) flag = false;
            }
        }

        removeBitIf(node);
        setWeight(node, value);
        return value; 
    }
}

Bits bestPlaying(int node, int depth, bool isMaximizing){
    int ans = 0;
    return getBits(ans);
}

