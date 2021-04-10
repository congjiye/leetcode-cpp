#include <cassert>
#include <iostream>

using namespace std;

double myPow(double x, int n) {
	if (x == 0) {
		return 0;
	}

	long long b = n;
	double res = 1.0;
	if (n < 0) {
		x = 1 / x;
		b = -b;
	}
	while (b > 0) {
		if (b & 1) {
			res *= x;
		}
		x *= x;
		b >>= 1;
	}
	return res;;
}

int main() {
	assert(myPow(2.00000, 10) == 1024.00000);
	assert(myPow(2.10000, 3) == 9.26100);;
	return EXIT_SUCCESS;
}