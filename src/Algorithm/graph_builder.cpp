#include <stdio.h>
#include <vector>
#include <queue>
#include "graph_builder.hpp"
#include "../Rules/bits.hpp"

using namespace std;

vector<int> graph[maxn];
double nodeWeights[maxn];
int depthNode[maxn];
Bits nodesPos[maxn];

int countNodes;

void build_graph(void){
    for(int i=0;i<maxn;i++) nodeWeights[i] = 0;
    countNodes = 1;
}
int HowManyNodes(void){
    return countNodes;
}
void removeBit(int node){
    nodesPos[node] = {0};
}
void removeBitIf(int node){
    if (depthNode[node] > 1) nodesPos[node] = {0};
}

void createGraph(Bits c){
    nodesPos[0] = c;
    depthNode[0] = 0;
}

void createGraph(int nodeFather, Bits u){
    if(nodeFather != -1) {
        nodesPos[countNodes] = u;
        graph[nodeFather].push_back(nodeFather);
        depthNode[countNodes] = depthNode[nodeFather] + 1;
        countNodes++;
    }	
}

void createGraph(int nodeFather, vector<Bits> & u){
    if(nodeFather != -1) {
        for (Bits son : u) {
            nodesPos[countNodes] = son;
            graph[nodeFather].push_back(countNodes);
            depthNode[countNodes] = depthNode[nodeFather] + 1;
            countNodes++;
        }
    }
}

void setWeight(int u, double weight){
    nodeWeights[u] = weight;
}

double getWeight(int u){
    return nodeWeights[u];
}

int getDepth(void){
    bool mark[maxn];
    for(int i=0;i<maxn;i++) mark[i] = false;
    
    queue<int> fila;
    int dist[maxn];
    
    for(int i=0;i<maxn;i++) dist[i]=0;
    fila.push(0);
    mark[0] = true;
    
    while(!fila.empty()){
        auto u = fila.front();
        for (auto v : graph[u]) {
            if(!mark[v]){
                dist[v] =dist[u]+1;
                fila.push(v);
                mark[v] = true;
            }  
        }
    }

    return dist[countNodes];
}

int getDepthFromNode(int u){
    return depthNode[u];
}

Bits getBits(int node){
    return nodesPos[node]; 
}
std::vector<int> getSon(int son){
    return graph[son];
}
void printGraph(void){
    for (int i = 0; i < countNodes; i++) {
        printf("The node: %d has connections with this Bitss-> ", i);
        for (int j = 0; j < graph[i].size(); j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
void printWeightGraph(void){
    for (int i = 0; i < countNodes; i++) {
        printf("The node: %d has this weight-> ", i);
        printf("%lf\n", nodeWeights[i]);
    }
}