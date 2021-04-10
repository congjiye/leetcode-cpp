#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int minArray(vector<int>& numbers) {
	int i = 0, j = numbers.size() - 1;
	while (i < j) {
		int m = (i + j) >> 1;
		if (numbers[m] > numbers[j]) {
			i = m + 1;
		}
		else if (numbers[m] < numbers[j]) {
			j = m;
		}
		else {
			j--;
		}
	}
	return numbers[i];
}

int main() {
	vector<int> first{ 3,4,5,1,2 };
	vector<int> second{ 2,2,2,0,1 };
	assert(minArray(first) == 1);
	assert(minArray(second) == 0);
	return EXIT_SUCCESS;
}