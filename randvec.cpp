#include "randvec.h"

using std::vector;

vector<int> randomVector(int len, int min, int max) {
    vector<int> ret;
    std::random_device rd;
    std::mt19937 rng(rd);
    std::uniform_int_distribution<int> uni(min, max);
    for (int i = 0; i < len; i++) {
        auto random_integer = uni(rng);
        ret.push_back(random_integer);
    }

    return ret;
}
