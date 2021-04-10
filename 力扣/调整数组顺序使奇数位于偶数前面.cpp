#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
vector<int> exchange(vector<int>& nums) {
	int i = 0, j = nums.size() - 1;
	while (i < j) {
		if (nums[i] % 2 != 0) {
			i++;
			continue;
		}

		if (nums[j] % 2 == 0) {
			j--;
			continue;
		}
		
		int temp = nums[i];
		nums[i++] = nums[j];
		nums[j--] = temp;
	}
	return nums;
}

int main() {
	vector<int> nums{ 1, 2, 3, 4 };
	vector<int> res{ 1, 3, 2, 4 };
	assert(exchange(nums) == res);
	return EXIT_SUCCESS;
}