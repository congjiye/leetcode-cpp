#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
int removeDuplicates(vector<int>& nums) {
	if (nums.empty()) {
		return 0;
	}

	int i = 0;
	for (int j = 1; j < nums.size(); ++j) {
		if (nums[j] == nums[i]) {
			continue;
		}

		nums[++i] = nums[j];
	}
	return ++i;
}

int main() {
	vector<int> nums{ 1,1,2 };
	assert(removeDuplicates(nums) == 2);
	return EXIT_SUCCESS;
}