#include <bitset>
#include <stdint.h>

int popcount(int64_t bit){
    int count = 0;
    while (bit) {
       count++;
       bit &= bit - 1; 
    }
    return count;
}

int lsb(int64_t bit){
    std::bitset<64> bits(bit);
    return bits._Find_first();
}

int64_t northFillBlock(int64_t b, int64_t emp){
    b |= emp & (b <<  8);
    emp &=(emp <<  8);
    b |= emp & (b << 16);
    emp &=(emp << 16);
    b |= emp & (b << 32);
    return b;
}
