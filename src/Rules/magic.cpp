#include "magic.hpp"

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

uint64_t rookmagic[64];
uint64_t bishopmagic[64];

//implementar todos os movimentos possíveis em um tabuleiro vazio
uint64_t movebishop[64];
uint64_t moverook[64] = {72340172838076926ULL,144680345676153597ULL,289360691352306939ULL,578721382704613623ULL,1157442765409226991ULL,2314885530818453727ULL,4629771061636907199ULL,9259542123273814143ULL,72340172838141441ULL,144680345676217602ULL,289360691352369924ULL,578721382704674568ULL,1157442765409283856ULL,2314885530818502432ULL,4629771061636939584ULL,9259542123273813888ULL,72340172854657281ULL,144680345692602882ULL,289360691368494084ULL,578721382720276488ULL,1157442765423841296ULL,2314885530830970912ULL,4629771061645230144ULL,9259542123273748608ULL,72340177082712321ULL,144680349887234562ULL,289360695496279044ULL,578721386714368008ULL,1157442769150545936ULL,2314885534022901792ULL,4629771063767613504ULL,9259542123257036928ULL,72341259464802561ULL,144681423712944642ULL,289361752209228804ULL,578722409201797128ULL,1157443723186933776ULL,2314886351157207072ULL,4629771607097753664ULL,9259542118978846848ULL,72618349279904001ULL,144956323094725122ULL,289632270724367364ULL,578984165983651848ULL,1157687956502220816ULL,2315095537539358752ULL,4629910699613634624ULL,9259541023762186368ULL,143553341945872641ULL,215330564830528002ULL,358885010599838724ULL,645993902138460168ULL,1220211685215703056ULL,2368647251370188832ULL,4665518383679160384ULL,9259260648297103488ULL,18302911464433844481ULL,18231136449196065282ULL,18087586418720506884ULL,17800486357769390088ULL,17226286235867156496ULL,16077885992062689312ULL,13781085504453754944ULL,9187484529235886208ULL};

uint64_t attackrook[64][size];
uint64_t attackbishop[64][size];

int magicindexrook(uint64_t occupied, int square, uint64_t magic){
    uint64_t blockers = occupied & moverook[square] & 35604928818740736ULL;
    uint64_t index = (blockers * magic) >> 52;
    return (int)index;
}

//Retorna se o número mágico gera conflitos ou não;
//Caso gere, retorna 0;
int testmagicrook(int square, uint64_t magic) {
    uint64_t moves = moverook[square];
    uint64_t n = 0ULL;    
    int count = 0;
    do {
      uint64_t indices[size] = {0ULL};
      uint64_t attack = genrookattack(1ULL<<square, ~n);
      int index = magicindexrook(n, square, magic);
      if (indices[index] && (indices[index] != attack)){
        return 0;
      }
      else{
        indices[index] = attack;
      }
      //Passa por todos as ocupâncias possíveis, considerando
      //o raio de movimento da peça
      n = (n - moves) & moves;
      count++;
    } while (n);
    return 1;
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

