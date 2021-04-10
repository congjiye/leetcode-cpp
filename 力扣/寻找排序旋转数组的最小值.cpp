#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
int findMin(vector<int>& nums) {
	int left = 0, right = nums.size() - 1;
	if (nums[left] <= nums[right]) {
		return nums[left];
	}

	int mid = (left + right) / 2;
	while (left < right - 1) {
		if (nums[mid] < nums[right]) {
			right = mid;
		}
		else {
			left = mid;
		}

		mid = (left + right) / 2;
	}

	return nums[++mid];
}

int main() {
	vector<int> nums{ 3,4,5,1,2 };
	assert(findMin(nums) == 1);
	return EXIT_SUCCESS;
}