#ifndef GRAPHBUILDER_HPP_H
#define GRAPHBUILDER_HPP_H

#include "../Rules/bits.hpp"

#define maxn 100010

void build_graph(void);
int HowManyNodes(void);
void removeBit(int node);
void removeBitIf(int node);
void createGraph(Bits c);
void createGraph(int nodeFather, Bits u);
void setWeight(int u, double weight);
double getWeight(int u);
int getDepth(void);
int getDepthFromNode(int u);
Bits getBits(int node);
std::vector<int> getSon(int son);
void printGraph(void);
void printWeightGraph(void);


#endif