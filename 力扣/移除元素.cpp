#include <bits/stdc++.h>

using namespace std;
int removeElement(vector<int>& nums, int val) {
	int n = nums.size();
	if (n == 0) {
		return 0;
	}

	int slow = 0, fast = 0;
	while (fast < n) {
		if (nums[fast] != val) {
			nums[slow++] = nums[fast];
		}
		++fast;
	}
	return slow;
}

int main() {
	vector<int> nums{ 3,2,2,3 };
	assert(removeElement(nums, 3));
	return EXIT_SUCCESS;
}