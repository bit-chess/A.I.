#include <bitset>
#include <stdint.h>
#include <mask.hpp>

int popcount(uint64_t bit){
    int count = 0;
    while (bit) {
       count++;
       bit &= bit - 1; 
    }
    return count;
}

int lsb(uint64_t bit){
    std::bitset<64> bits(bit);
    return bits._Find_first();
}

uint64_t northFill(uint64_t pieces, uint64_t emp){
    pieces |= emp & (pieces <<  8);
    emp &=(emp <<  8);
    pieces |= emp & (pieces << 16);
    emp &=(emp << 16);
    pieces |= emp & (pieces << 32);
    return pieces;
}
uint64_t northattack(uint64_t pieces, uint64_t emp){
    pieces |= emp & (pieces <<  8);
    emp &=(emp <<  8);
    pieces |= emp & (pieces << 16);
    emp &=(emp << 16);
    pieces |= emp & (pieces << 32);
    return (pieces<<8);
}

uint64_t southfill(uint64_t pieces, uint64_t emp){
    pieces |= emp & (pieces >>  8);
    emp &=(emp >>  8);
    pieces |= emp & (pieces >> 16);
    emp &=(emp >> 16);
    pieces |= emp & (pieces >> 32);
    return pieces;
}

uint64_t southattack(uint64_t pieces, uint64_t emp){
    pieces |= emp & (pieces >>  8);
    emp &=(emp >>  8);
    pieces |= emp & (pieces >> 16);
    emp &=(emp >> 16);
    pieces |= emp & (pieces >> 32);
    return (pieces>>8);
}

uint64_t swfill(uint64_t pieces, uint64_t emp){
    emp &= nothfile;
    pieces |= emp & (pieces >> 9);
    emp &=(emp >> 9);
    pieces |= emp & (pieces >> 18);
    emp &=(emp >> 18);
    pieces |= emp & (pieces >> 36);
    return pieces;
}

uint64_t swattack(uint64_t pieces, uint64_t emp){
    emp &= nothfile;
    pieces |= emp & (pieces >> 9);
    emp &=(emp >> 9);
    pieces |= emp & (pieces >> 18);
    emp &=(emp >> 18);
    pieces |= emp & (pieces >> 36);
    return ((pieces>>9) & nothfile);
}

uint64_t nwfill(uint64_t pieces, uint64_t emp){
    emp &= nothfile;
    pieces |= emp & (pieces << 7);
    emp &=(emp << 7);
    pieces |= emp & (pieces <<14);
    emp &=(emp << 14);
    pieces |= emp & (pieces << 28);
    return pieces;
}

uint64_t nwattack(uint64_t pieces, uint64_t emp){
    emp &= nothfile;
    pieces |= emp & (pieces << 7);
    emp &=(emp << 7);
    pieces |= emp & (pieces <<14);
    emp &=(emp << 14);
    pieces |= emp & (pieces << 28);
    return ((pieces<<7) & nothfile);
}

uint64_t nefill(uint64_t pieces, uint64_t emp){
    emp &= notafile;
    pieces |= emp & (pieces << 9);
    emp &=(emp << 9);
    pieces |= emp & (pieces <<18);
    emp &=(emp << 18);
    pieces |= emp & (pieces << 36);
    return pieces;
}

uint64_t neattack(uint64_t pieces, uint64_t emp){
    emp &= notafile;
    pieces |= emp & (pieces << 9);
    emp &=(emp << 9);
    pieces |= emp & (pieces <<18);
    emp &=(emp << 18);
    pieces |= emp & (pieces << 36);
    return pieces<<9 & notafile;
}

uint64_t sefill(uint64_t pieces, uint64_t emp){
    emp &= notafile;
    pieces |= emp & (pieces >> 7);
    emp &=(emp >> 7);
    pieces |= emp & (pieces >> 14);
    emp &=(emp >> 14);
    pieces |= emp & (pieces >> 28);
    return pieces;
}

uint64_t seattack(uint64_t pieces, uint64_t emp){
    emp &= notafile;
    pieces |= emp & (pieces >> 7);
    emp &=(emp >> 7);
    pieces |= emp & (pieces >> 14);
    emp &=(emp >> 14);
    pieces |= emp & (pieces >> 28);
    return pieces>>7 & notafile;
}


uint64_t westfill(uint64_t pieces, uint64_t emp) {
   emp &= nothfile;
   pieces |= emp & (pieces >> 1);
   emp &= (emp >> 1);
   pieces |= emp & (pieces >> 2);
   emp &= (emp >> 2);
   pieces |= emp & (pieces >> 4);
   return pieces;
}

uint64_t westattack(uint64_t pieces, uint64_t emp) {
   emp &= nothfile;
   pieces |= emp & (pieces >> 1);
   emp &= (emp >> 1);
   pieces |= emp & (pieces >> 2);
   emp &= (emp >> 2);
   pieces |= emp & (pieces >> 4);
   return pieces>>1 & nothfile;
}

uint64_t eastfill(uint64_t pieces, uint64_t emp) {
   emp &= notafile;
   pieces |= emp & (pieces << 1);
   emp &= (emp << 1);
   pieces |= emp & (pieces << 2);
   emp &= (emp << 2);
   pieces |= emp & (pieces << 4);
   return pieces;
}

uint64_t eastattack(uint64_t pieces, uint64_t emp) {
   emp &= notafile;
   pieces |= emp & (pieces << 1);
   emp &= (emp << 1);
   pieces |= emp & (pieces << 2);
   emp &= (emp << 2);
   pieces |= emp & (pieces << 4);
   return pieces<<1 & notafile;
}

uint64_t genrook()