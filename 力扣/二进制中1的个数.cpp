#include <iostream>
#include <cassert>

using namespace std;
int hammingWeight(uint32_t n) {
	int res = 0;
	while (n > 0) {
		res += 1;
		n &= (n - 1);
	}
	return res;
}

int main() {
	assert(hammingWeight(9) == 2);
	return EXIT_SUCCESS;
}