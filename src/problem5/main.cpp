#include <iostream>
#include <cinttypes>
#include "../util.h"

using namespace std;

uint64_t factorial(uint64_t n)
{
    if (n == 1 || n == 0)
        return 1;

    return factorial(n - 1) * n;
}

uint64_t smallest_multiple(uint64_t max) {
    uint64_t fak = factorial(max);
    for (uint64_t i = 1; i < fak; i++) {
        for (uint64_t d = 1; d <= max; ++d) {
            if (i % d != 0) {
                break;
            }
            if (d == max) {
                return i;
            }
        }
    }
    return fak;
}

int main() {
    Stopwatch sw{};
    sw.start();
    uint64_t max = 20;

    cout << "Result: " << smallest_multiple(max) << endl;
    cout << sw.get();
    return 0;
}