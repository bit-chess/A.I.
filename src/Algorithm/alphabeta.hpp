#ifndef ALPHABETA_HPP
#define ALPHABETA_HPP

#include "../Rules/bits.hpp"

const int inf = 1e9+7;

void AlphaBeta(Bits bit);
double algorithm(int node, int depth, double a, double b, bool isMaximizing);
Bits bestPlaying(int node, int depth, bool isMaximizing);

#endif