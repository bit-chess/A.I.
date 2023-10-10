#include <magic.hpp>
#include <random>

int main(){
    int k = 0;
    uint64_t magic = 0LL;
    std::random_device rd;
    std::mt19937_64 generator(rd());
    std::uniform_int_distribution<uint64_t> distribution(0, std::numeric_limits<uint64_t>::max());
    
    while(k==0) {
        uint64_t random_number = distribution(generator) & distribution(generator) & distribution(generator);
        int number = testmagicrook(24, random_number);
        k = number;
        magic = random_number;
    }
    printf("Numb%d", k);
}