#include "magic.hpp"

uint64_t rookmagic[64];
uint64_t bishopmagic[64];

//implementar todos os movimentos possíveis em um tabuleiro vazio
uint64_t movebishop[64];
uint64_t moverook[64];

uint64_t attackrook[64][16000];
uint64_t attackbishop[64][32000];

uint16_t magicindexrook(uint64_t occupied, int square){
    uint64_t blockers = occupied & moverook[square];
    uint64_t index = (blockers * rookmagic[square]) >> (57);
    return (uint16_t)index;
}

//Retorna se o número mágico gera conflitos ou não;
//Caso gere, retorna 0;
int testmagicrook(int square, uint64_t magic) {
    uint64_t indices[1<<16] = {0};
    uint64_t moves = 0b0000100000001000000010000000100011110111000010000000100000001000ULL;
    uint64_t n = 0;
    rookmagic[square] = magic;
    int count = 0;
    do {      
      uint64_t attack = genrookattack(1<<square, ~n);
      uint16_t index = magicindexrook(n, square);
      if (indices[index] && (indices[index] != attack)){
        return 0;
      }
      else{
        if(indices[index] == attack){
          count++;
        }
        indices[index] = attack;
      }
      //Passa por todos as ocupâncias possíveis, considerando
      //o raio de movimento da peça
      n = (n - moves) & moves;
    } while (n);
    return count;
}
/*
int testmagicbishop(int square, uint64_t magic) {
    uint64_t indices[1<<16] = {0};
    uint64_t moves = movebishop[square];
    uint64_t n = 0;
    do {
      uint64_t occupied = n;
      uint64_t attack = genbishopattack(1<<square, ~occupied);
      uint16_t magic = magicindexbishop(occupied, square);
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

