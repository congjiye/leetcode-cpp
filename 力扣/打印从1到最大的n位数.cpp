#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;
vector<int> printNumbers(int n) {
	vector<int> res;
	int right = pow(10, n);
	for (int i = 1; i < right; ++i) {
		res.emplace_back(i);
	}
	return res;
}

int main() {
	vector<int> res{ 1,2,3,4,5,6,7,8,9 };
	assert(printNumbers(1) == res);
	return EXIT_SUCCESS;
}