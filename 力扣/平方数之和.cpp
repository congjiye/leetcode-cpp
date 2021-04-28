#include <bits/stdc++.h>

using namespace std;
bool judgeSquareSum(int c) {
	long a = sqrt(c);
	for (long i = 0; i <= a; ++i) {
		double b = sqrt(c - i * i);
		if (b == (int)b) {
			return true;
		}
	}
	return false;
}

int main() {
	assert(judgeSquareSum(5));
	assert(!judgeSquareSum(3));
	return EXIT_SUCCESS;
}