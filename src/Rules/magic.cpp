#include "magic.hpp"
#include <vector>

const int size = 4096;

int rookshift[64] = {
  12, 11, 11, 11, 11, 11, 11, 12,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  11, 10, 10, 10, 10, 10, 10, 11,
  12, 11, 11, 11, 11, 11, 11, 12
};

uint64_t bishopmagic[64];

//implementar todos os movimentos possíveis em um tabuleiro vazio
uint64_t movebishop[64];
uint64_t moverook [64] = {282578800148862ULL,565157600297596ULL,1130315200595066ULL,2260630401190006ULL,4521260802379886ULL,9042521604759646ULL,18085043209519166ULL,36170086419038334ULL,282578800180736ULL,565157600328704ULL,1130315200625152ULL,2260630401218048ULL,4521260802403840ULL,9042521604775424ULL,18085043209518592ULL,36170086419037696ULL,282578808340736ULL,565157608292864ULL,1130315208328192ULL,2260630408398848ULL,4521260808540160ULL,9042521608822784ULL,18085043209388032ULL,36170086418907136ULL,282580897300736ULL,565159647117824ULL,1130317180306432ULL,2260632246683648ULL,4521262379438080ULL,9042522644946944ULL,18085043175964672ULL,36170086385483776ULL,283115671060736ULL,565681586307584ULL,1130822006735872ULL,2261102847592448ULL,4521664529305600ULL,9042787892731904ULL,18085034619584512ULL,36170077829103616ULL,420017753620736ULL,699298018886144ULL,1260057572672512ULL,2381576680245248ULL,4624614895390720ULL,9110691325681664ULL,18082844186263552ULL,36167887395782656ULL,35466950888980736ULL,34905104758997504ULL,34344362452452352ULL,33222877839362048ULL,30979908613181440ULL,26493970160820224ULL,17522093256097792ULL,35607136465616896ULL,9079539427579068672ULL,8935706818303361536ULL,8792156787827803136ULL,8505056726876686336ULL,7930856604974452736ULL,6782456361169985536ULL,4485655873561051136ULL,9115426935197958144ULL};
uint64_t attackrook[64][size];
uint64_t attackbishop[64][size];

int magicindexrook(uint64_t occupied, int square, uint64_t magic){
    uint64_t blockers = occupied & moverook[square];
    uint64_t index = (blockers * magic) >> 52;
    return (int)index;
}

//Retorna se o número mágico gera conflitos ou não;
//Caso gere, retorna 0;
int testmagicrook(int square, uint64_t magic) {    
    uint64_t n = 0ULL;    
    uint64_t indices[size] = {0ULL};
    do {      
      uint64_t attack = genrookattack(1ULL<<square, ~n);
      int index = magicindexrook(n, square, magic);
      if ((indices[index] != 0ULL) && (indices[index] != attack)){
        return 0;
      }
      else{
        indices[index] = attack;
      }
      //Passa por todos as ocupâncias possíveis, considerando
      //o raio de movimento da peça
      n = (n - moverook[square]) & moverook[square];
      
    } while (n != 0ULL);
    return 1;
}

std::vector<uint64_t> createattackarray (int square, uint64_t magic){
    uint64_t moves = moverook[square];
    uint64_t n = 0ULL;    
    std::vector<uint64_t> indices(4096, 0ULL);
    do {
      
      uint64_t attack = genrookattack(1ULL<<square, ~n);
      int index = magicindexrook(n, square, magic);
      indices[index] = attack;
      
      //Passa por todos as ocupâncias possíveis, considerando
      //o raio de movimento da peça
      n = (n - moves) & moves;
      
    } while (n);
    return indices;
}
/*
int testmagicbishop(int square, uint64_t magic) {
    uint64_t indices[1<<16] = {0};
    uint64_t moves = movebishop[square];
    uint64_t n = 0;
    do {
      uint64_t occupied = n;
      uint64_t attack = genbishopattack(1<<square, ~occupied);
      int magic = magicindexbishop(occupied, square);
      if (!indices[magic] && (indices[magic] != attack)){
        return 0;
      }
      else{
        indices[magic] = attack;
      }
      n = (n - moves) & moves;
    } while (n);
    return 1;
}*/

