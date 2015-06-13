#include <iostream>
#include <vector>
#include <math.h>

#include "../util.h"

using namespace std;

int main()
{
    Stopwatch sw;

    sw.start();

	size_t n = 600851475143;
    size_t z = n;
	vector<size_t> factors;

    size_t s = static_cast<size_t>(sqrt(n));
    for (size_t i = 2; i <= s; i++) {
        if (z % i == 0) {
            factors.push_back(i);
            z /= i;
            i = 2;
        }
        if (i == s && z != 1) {
            factors.push_back(z);
        }
    }

    cout << strjoin(factors, " * ") << endl;
    cout << sw.get();
	return 0;
}