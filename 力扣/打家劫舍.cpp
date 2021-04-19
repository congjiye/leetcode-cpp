#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;
int rob(vector<int>& nums) {
	int size = nums.size();

	vector<int> dp(size, 0);
	dp[0] = nums[0];
	if (size == 1) {
		return dp[0];
	}

	dp[1] = max(nums[0], nums[1]);
	for (int i = 2; i < size; ++i) {
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}

	return dp[size - 1];
}

int main() {
	vector<int> nums{ 1,2,3,1 };
	assert(rob(nums) == 4);
	return EXIT_SUCCESS;
}