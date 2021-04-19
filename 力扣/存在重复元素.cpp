#include <iostream>
#include <cassert>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	int n = nums.size();
	set<int> rec;
	for (int i = 0; i < n; i++) {
		auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
		if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
			return true;
		}
		rec.insert(nums[i]);
		if (i >= k) {
			rec.erase(nums[i - k]);
		}
	}
	return false;
}

int main() {
	vector<int> nums{ 1,0,1,1 };
	assert(containsNearbyAlmostDuplicate(nums, 1, 2));
	return EXIT_SUCCESS;
}