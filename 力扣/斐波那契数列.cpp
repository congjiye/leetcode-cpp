#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int fib(int n) {
	if (n == 0) {
		return 0;
	}

	vector<int> v(n + 1);
	v[0] = 0;
	v[1] = 1;
	for (int i = 2; i <= n; ++i) {
		v[i] = v[i - 1] + v[i - 2];
		v[i] %= 1000000007;
	}
	return v[n];
}

int main() {
	assert(fib(2) == 1);
	assert(fib(5) == 5);
	return EXIT_FAILURE;
}