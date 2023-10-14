#include "../Rules/magic.hpp"
#include <random>

extern uint64_t rookmagic[64];
extern uint64_t moverook[64];

int main(){
    int k = 0;
    uint64_t magic = 0ULL;
    int square = 27;
    rookmagic[square] = 0ULL;
    moverook[square] = 0b0000100000001000000010000000100011110111000010000000100000001000ULL;
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<uint64_t> distribution(0ULL, 0xFFFFFFFFFFFFFFFFULL);
    
    for(int i = 0; i<1000000; i++) {
        
        uint64_t random_number = distribution(generator) & distribution(generator) & distribution(generator);
        if(popcount((moverook[square] * random_number) & 0xFF00000000000000ULL) < 6) continue;
        int number = testmagicrook(square, random_number);
        k = number;
        magic = random_number;
        if(k!=0){
            printf("%lu", magic);
        }
    }
    
}