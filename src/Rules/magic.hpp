#ifndef MAGIC_HPP
#define MAGIC_HPP

#include <stdlib.h>
#include "manipulator.hpp"

extern const uint64_t moverook[64];

uint16_t magicindexrook(uint64_t occupied, int square, uint64_t magic);
int testmagicrook(int square, uint64_t magic);


#endif