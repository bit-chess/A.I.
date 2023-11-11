#ifndef MANIPULATOR_HPP
#define MANIPULATOR_HPP

#include <stdint.h>

int popcount(uint64_t bit);
int lsb(uint64_t bit);
int msb(uint64_t bit);
uint64_t northFill(uint64_t pieces, uint64_t emp);
uint64_t northattack(uint64_t pieces, uint64_t emp);
uint64_t southfill(uint64_t pieces, uint64_t emp);
uint64_t southattack(uint64_t pieces, uint64_t emp);
uint64_t swfill(uint64_t pieces, uint64_t emp);
uint64_t swattack(uint64_t pieces, uint64_t emp);
uint64_t nwfill(uint64_t pieces, uint64_t emp);
uint64_t nwattack(uint64_t pieces, uint64_t emp);
uint64_t nefill(uint64_t pieces, uint64_t emp);
uint64_t neattack(uint64_t pieces, uint64_t emp);
uint64_t sefill(uint64_t pieces, uint64_t emp);
uint64_t seattack(uint64_t pieces, uint64_t emp);
uint64_t westfill(uint64_t pieces, uint64_t emp);
uint64_t westattack(uint64_t pieces, uint64_t emp);
uint64_t eastfill(uint64_t pieces, uint64_t emp);
uint64_t eastattack(uint64_t pieces, uint64_t emp);
uint64_t genrookattack(uint64_t pieces, uint64_t emp);
uint64_t genbishopattack(uint64_t pieces, uint64_t emp);
uint64_t genrookmask(uint64_t pieces);


#endif