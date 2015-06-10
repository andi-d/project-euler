#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool is_palindrome(size_t n) {
    stringstream ss;
    ss << n;
    auto d = ss.str();

    string rev{d};
    reverse(d.begin(), d.end());
    return d == rev;
}

int main() {
    size_t max = 0;
    for (size_t x = 1000; x > 100; x--) {
        for (size_t y = 1000; y > 100; y--) {
            auto n = x * y;
            if (is_palindrome(n))
                max = std::max(n, max);
        }
    }
    cout << max;
}