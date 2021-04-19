#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;
int rob(vector<int>& nums) {
	int size = nums.size();
	vector<int> dp(size, 0);

	if (size == 1) {
		return nums[0];
	}

	if (size == 2) {
		return max(nums[0], nums[1]);
	}

	return max(robRange(nums, 0, size - 1), robRange(nums, 1, size));
}

int robRange(vector<int>& nums, int start, int end) {
	int first = nums[start], second = max(nums[start], nums[start + 1]);
	for (int i = start + 2; i < end; ++i) {
		int temp = second;
		second = max(first + nums[i], second);
		first = temp;
	}
	return second;
}

int main() {
	vector<int> nums{ 1, 2, 1, 1 };
	assert(rob(nums) == 2);
	return EXIT_SUCCESS;
}