#include <magic.hpp>

int magicindexrook(int64_t occupied, int square){
    int64_t blockers = occupied & moverook[square];
    int64_t index = (blockers * rookmagic[square]) >> (64 - popcount(blockers));
    return (int)index;
}

//incompleto
void testmagicrook(int square, int64_t magic) {
    vector<int64_t> indexes;
    int64_t moves = moverook[square];
    int n = popcount(moves);
    for (int i = 0; i<(2<<n); i++) {
        int64_t test = moves;
        int x = lsb(test);
        while (test != 0ll) {
            
        }
    }
}

