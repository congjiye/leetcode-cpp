#include <iostream>
#include <vector>
#include <set>
#include <cassert>

using namespace std;
bool search(vector<int>& nums, int target) {
	int left = 0, right = nums.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (nums[mid] == target) {
			return true;
		}

		if (nums[mid] == nums[right] && nums[mid] == nums[left]) {
			--right;
			++left;
		}
		else if (nums[mid] <= nums[right]) {
			if (target <= nums[right] && target > nums[mid]) {
				left = ++mid;
			}
			else {
				right = --mid;
			}
		}
		else {
			if (target >= nums[left] && target < nums[mid]) {
				right = --mid;
			}
			else {
				left = ++mid;
			}
		}
	}

	return false;
}

int main() {
	vector<int> nums{ 2,5,6,0,0,1,2 };
	assert(search(nums, 0));
	return EXIT_SUCCESS;
}