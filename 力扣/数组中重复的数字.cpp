#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
int find_repeat_number(vector<int>& nums) {
	for (int i = 0; i < nums.size(); ++i) {
		while (nums[i] != i) {
			if (nums[i] == nums[nums[i]]) {
				return nums[i];
			}
			int temp = nums[i];
			nums[i] = nums[temp];
			nums[temp] = temp;
		}
	}
	return -1;
}

int main() {
	vector<int> input{ 2, 3, 1, 0, 2, 5, 3 };
	assert(find_repeat_number(input) == 2 || find_repeat_number(input) == 3);
	return EXIT_SUCCESS;
}