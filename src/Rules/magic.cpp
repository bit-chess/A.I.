#include <magic.hpp>

int magicindexrook(uint64_t occupied, int square){
    uint64_t blockers = occupied & moverook[square];
    uint64_t index = (blockers * rookmagic[square]) >> (64 - popcount(blockers));
    return (int)index;
}

//incompleto
void testmagicrook(int square, uint64_t magic) {
    vector<uint64_t> indexes;
    uint64_t moves = moverook[square];
    int n = popcount(moves);
    for (int i = 0; i<(2<<n); i++) {
        uint64_t test = moves;
        int x = lsb(test);
        while (test != 0ll) {
            
        }
    }
}

