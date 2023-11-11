#include "../Rules/manipulator.hpp"
#include <iostream>
using namespace std;

int main(){
    cout << "uint64_t moverook [64] = {";

    for(int i = 0; i<64; i++){
        std:cout << genrookmask(1ULL<<i) << "ULL,";
    }
    cout << "}";
}