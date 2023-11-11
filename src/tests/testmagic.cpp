#include "../Rules/magic.hpp"
#include <random>
#include <iostream>


int main(){
    
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<uint64_t> distribution(0ULL, 0xFFFFFFFFFFFFFFFFULL);
    
    
    std::cout << "const uint64_t rookmagic[64] = {";
    for (int j = 0; j<64; j++){
        int flag = 1;
        for(int i = 0; i<100000 && flag; i++) {        
            uint64_t random_number = distribution(generator) & distribution(generator) & distribution(generator);
            int number = testmagicrook(j, random_number);
            if(number) {
                std::cout << random_number << "ULL,";
                flag = !flag;
            }
        }
    }
    std::cout << "}";
    
}