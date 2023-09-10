#include <bitset>
#include <stdint.h>

int popcount(int64_t bit){
    int count = 0;
    while (bit) {
       count++;
       x &= x - 1; 
    }
    return count;
}

int lsb(int64_t bit){
    std::bitset<64> bits(bit);
    return bits._Find_fist();
}

int64_t northFillBlock(int64_t b, int64_t emp){
    b |= emp & (g <<  8);
    emp &=     (p <<  8);
    b |= emp & (g << 16);
    emp &=     (p << 16);
    b |= emp & (g << 32);
    return b;
}
