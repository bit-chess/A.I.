#include "../Rules/magic.hpp"
#include <random>



int main(){
    uint64_t magic;
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<uint64_t> distribution(0ULL, 0xFFFFFFFFFFFFFFFFULL);
    const int mask =10340688612642882047ULL;
    printf("const int rookmagic[64] = {");
    for (int j = 0; j<64; j++){
        for(int i = 0; i<100000000; i++) {        
            uint64_t random_number = distribution(generator) & distribution(generator) & distribution(generator);
            if(popcount(((moverook[j] & mask) * magic) & 0xFF00000000000000ULL) < 6) continue;
            int number = testmagicrook(j, random_number);
            magic = random_number;
            if(magic == 0) continue;
            if(number!=0){
                printf("%luULL,", magic);
                break;
            }
        }
    }
    printf("}");
    
}