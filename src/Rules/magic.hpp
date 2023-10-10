#ifndef MAGIC_HPP
#define MAGIC_HPP

#include <cstdlib.h>
#include <stdint.h>
#include <manipulator.hpp>

uint64_t rookmagic[64];
uint64_t bishopmagic[64];

//implementar todos os movimentos possíveis em um tabuleiro vazio
uint64_t movebishop[64];
uint64_t moverook[64];

uint64_t attackrook[64][16000];
uint64_t attackbishop[64][32000];

int magicindexrook(uint64_t occupied, int square);
void testmagicrook(int square, uint64_t magic);


#endif