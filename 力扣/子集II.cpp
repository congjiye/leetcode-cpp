#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;
class Solution {
public:
	vector<vector<int>> ans;

	void dfs(vector<int>& nums, int j, vector<int> path) {
		if (j == nums.size()) {
			ans.emplace_back(path);
			return;
		}

		int k = j;
		while (k < nums.size() && nums[k] == nums[j]) {
			++k;
		}
		dfs(nums, k, path);
		for (int i = j; i < k; ++i) {
			path.push_back(nums[i]);
			dfs(nums, k, path);
		}
	}

	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		dfs(nums, 0, vector<int>());
		return ans;
	}
};

int main() {
	vector<int> input{ 1,2,3 };
	vector<vector<int>> result{ {}, {1},{1,2},{1,2,2},{2},{2,2} };
	Solution s;
	vector<vector<int>> output = s.subsetsWithDup(input);
	assert(result == output);
	return EXIT_SUCCESS;
}