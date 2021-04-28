#include <bits/stdc++.h>

using namespace std;
vector<int> largestDivisibleSubset(vector<int>& nums) {
	int n = nums.size();
	if (n <= 0 || n == 1) {
		return nums;
	}

	sort(nums.begin(), nums.end());
	vector<int> dp(n, 1);

	int max_value = 0;
	int max_size = 0;
	int max_index = -1;
	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (nums[i] % nums[j] == 0) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		if (dp[i] > max_size) {
			max_size = dp[i];
			max_value = nums[i];
			max_index = i;
		}
	}

	vector<int> result;
	while (max_size > 0) {
		if (dp[max_index] == max_size && max_value % nums[max_index] == 0) {
			result.emplace_back(nums[max_index]);
			--max_size;
			max_value = nums[max_index];
		}

		--max_index;
	}

	sort(result.begin(), result.end());
	return result;
}

int main() {
	vector<int> nums{ 1 };
	vector<int> output{ 8,2,4,1 };
	assert(largestDivisibleSubset(nums) == output);
	return EXIT_SUCCESS;
}