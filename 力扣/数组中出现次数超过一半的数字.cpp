#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;
int majorityElement(vector<int>& nums) {
	int x = 0, vote = 0;
	for (auto num : nums) {
		if (vote == 0) {
			x = num;
		}
		vote += (num == x ? 1 : -1);
	}
	return x;
}

int main() {
	vector<int> input{ 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	assert(majorityElement(input) == 2);
	return EXIT_SUCCESS;
}