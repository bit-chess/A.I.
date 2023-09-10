#ifndef GRAPHBUILDER_HPP_H
#define GRAPHBUILDER_HPP_H

#include <vector>
#include "../Rules/bits.hpp"

const int maxn = 1e5+10;

void build_graph(void);
int HowManyNodes(void);
void removeBit(int node);
void removeBitIf(int node);
void createGraph(Bits c);
void createGraph(int nodeFather, Bits u);
void createGraph(int nodeFather, std::vector<Bits> & u);
void setWeight(int u, double weight);
double getWeight(int u);
int getDepth(void);
int getDepthFromNode(int u);
Bits getBits(int node);
std::vector<int> getSon(int son);
void printGraph(void);
void printWeightGraph(void);


#endif