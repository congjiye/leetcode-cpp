#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
int search(vector<int>& nums, int target) {
	int low = 0, heigh = nums.size() - 1;
	int mid = (heigh - low) / 2;
	while (low <= heigh) {
		if (nums[mid] == target) {
			return mid;
		}

		if (nums[low] <= nums[mid]) {
			if (nums[low] <= target && target < nums[mid]) {
				heigh = --mid;
			}
			else {
				low = ++mid;
			}
		}
		else {
			if (nums[mid] < target && target <= nums[heigh]) {
				low = ++mid;
			}
			else {
				heigh = --mid;
			}
		}

		mid = (low + heigh) / 2;
	}
	return -1;
}

int main() {
	vector<int> nums{ 4,5,6,7,0,1,2 };
	assert(search(nums, 1) == 5);
	return EXIT_SUCCESS;
}