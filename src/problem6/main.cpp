#include <iostream>
#include <cinttypes>
#include <algorithm>
#include <numeric>
#include <vector>
#include "../util.h"

using namespace std;

uint64_t sum_of_squares(vector<uint64_t> in) {
    //auto res = accumulate(in.begin(), in.end(), uint64_t(0), [](uint64_t x, uint64_t i) {
    //    return x + (i * i);
    //});
    uint64_t res = 0;
    for (auto &x : in)
        res += x * x;
    return res;
}

uint64_t square_of_sum(vector<uint64_t> in) {
    //auto res = accumulate(in.begin(), in.end(), uint64_t(0));
    uint64_t res = 0;
    for (auto &x : in)
        res += x;
    return res * res;
}

int main() {
    size_t max = 100;
    std::vector<uint64_t> v(max);
    std::iota(v.begin(), v.end(), 1);
    cout << square_of_sum(v) - sum_of_squares(v) << endl;
    return 0;
}
