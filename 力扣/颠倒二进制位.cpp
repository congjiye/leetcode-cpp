#include <iostream>
#include <cassert>

using namespace std;
uint32_t reverseBits(uint32_t n) {
	uint32_t temp = 0;
	for (int i = 0; i < 32 && n > 0; ++i) {
		temp |= (n & 1) << (31 - i);
		n >>= 1;
	}
	return temp;
}

int main() {
	uint32_t input = 43251596;
	uint32_t output = reverseBits(input);
	uint32_t result = 964176192;
	assert(output == result);
	return EXIT_SUCCESS;
}