#include <iostream>
#include <cinttypes>

int fib(std::uint64_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	int a = 0;
	int b = 1;
	for (size_t i = 1; i < n; i++) {
		int next = a + b;
		a = b;
		b = next;
	}
	return b;
}

int main() {
	int sum = 0;
	int i = 1;
	int f = 0;

	while (true) {
		f = fib(i++);
		std::cout << f << ' ';
		if (f >= 4000000) {
			break;
		}
		if (f % 2 == 0) {
			sum += f;
		}
	}

	std::cout << std::endl << sum;
	std::cin.get();
	return 0;
}