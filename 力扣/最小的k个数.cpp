#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;
vector<int> getLeastNumbers(vector<int>& arr, int k) {
	sort(arr.begin(), arr.end());
	vector<int> result(k);
	memcpy(&result[0], &arr[0], sizeof(int) * k);
	//copy(arr.begin(), arr.begin() + k, result.begin());
	return result;
}

int main() {
	vector<int> input{ 3,2,1 };
	vector<int> output{ 1,2 };
	vector<int> result = getLeastNumbers(input, 2);
	assert(output == result);
	return EXIT_SUCCESS;
}