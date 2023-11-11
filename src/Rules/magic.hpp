#ifndef MAGIC_HPP
#define MAGIC_HPP

#include <stdlib.h>
#include <vector>
#include "manipulator.hpp"

int magicindexrook(uint64_t occupied, int square, uint64_t magic);
int testmagicrook(int square, uint64_t magic);
std::vector<uint64_t> createattackarray(int square, uint64_t magic);


#endif