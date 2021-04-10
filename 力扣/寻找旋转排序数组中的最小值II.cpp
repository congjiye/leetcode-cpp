#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
int findMin(vector<int>& nums) {
	int left = 0, right = nums.size() - 1;
	while (left < right) {
		int mid = (left + right) / 2;
		if (nums[mid] > nums[right]) {
			left = ++mid;
		}
		else if (nums[mid] < nums[right]) {
			right = mid;
		}
		else {
			--right;
		}
	}

	return nums[left];
}

int main() {
	vector<int> nums{ 1,3,5 };
	assert(findMin(nums) == 1);
	return EXIT_SUCCESS;
}