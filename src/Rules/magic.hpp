#ifndef MAGIC_HPP
#define MAGIC_HPP

#include <stdint.h>
#include <manipulator.hpp>

int64_t rookmagic[64];
int64_t bishopmagic[64];

//implementar todos os movimentos possíveis em um tabuleiro vazio
int64_t movebishop[64];
int64_t moverook[64];

int64_t attackrook[64][16000];
int64_t attackbishop[64][32000];

int magicindex(int64_t occupied, int square);
void testmagic(int square, int64_t magic);


#endif