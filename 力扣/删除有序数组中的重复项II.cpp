#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
int removeDuplicates(vector<int>& nums) {
	int j = 0;
	for (auto& num : nums) {
		if (j < 2 || num != nums[j - 2]) {
			nums[j++] = num;
		}
	}
	return j;
}

int main() {
	vector<int> nums{ 1,1,1,2,2,3 };
	assert(removeDuplicates(nums) == 5);
	return EXIT_SUCCESS;
}