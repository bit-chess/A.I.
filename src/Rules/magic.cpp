#include <magic.hpp>

uint16_t magicindexrook(uint64_t occupied, int square){
    uint64_t blockers = occupied & moverook[square];
    uint64_t index = (blockers * rookmagic[square]) >> (64 - popcount(blockers));
    return (uint16_t)index;
}

//Retorna se o número mágico gera conflitos ou não;
//Caso gere, retorna 0;
int testmagicrook(int square, uint64_t magic) {
    uint64_t indices[1<<16] = {0}
    uint64_t moves = moverook[square];
    uint64_t n = 0;
    int count = 0;
    do {
      uint64_t occupied = n;
      uint64_t attack = genrookattack(1<<square, ~occupied);
      uint16_t index = magicindexrook(occupied, square);
      if (!indices[index] && (indices[index] != attack)){
        return 0;
      }
      else{
        indices[index] = attack;
        count++
      }
      n = (n - moves) & moves;
    } while (n);
    return count;
}

int testmagicbishop(int square, uint64_t magic) {
    uint64_t indices[1<<16] = {0}
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
}

