#include <iostream>
#include <cassert>

using namespace std;
bool isUgly(int n) {
	if (n == 0) {
		return false;
	}
	if (n == 1) {
		return true;
	}

	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else if (n % 3 == 0) {
			n /= 3;
		}
		else if (n % 5 == 0) {
			n /= 5;
		}
		else {
			return false;
		}
	}

	return true;
}

int main() {
	assert(isUgly(6));
	assert(isUgly(8));
	assert(isUgly(14) == false);
	return EXIT_SUCCESS;
}