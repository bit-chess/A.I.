#include <bits/stdc++.h>

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
    return bits._FindFist();
}
