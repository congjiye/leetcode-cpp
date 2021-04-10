#include <iostream>
#include <vector>
#include <cassert>
#include <deque>

using namespace std;
vector<int> max_sliding_window(vector<int>& nums, int k) {
	int size = nums.size();
	if (size == 0 || k == 0) {
		return {};
	}

	deque<int> window;
	vector<int> res;
	for (int j = 0, i = 1 - k; j < size; ++i, ++j) {
		if (i > 0 && window.front() == (i - 1)) {
			window.pop_front();
		}
		while (!window.empty() && nums[window.back()] < nums[j]) {
			window.pop_back();
		}
		window.push_back(j);
		if (i >= 0) {
			res.emplace_back(nums[window.front()]);
		}
	}
	return res;
}

int main() {
	vector<int> nums{ 1,3,-1,-3,5,3,6,7 };
	int k = 3;
	vector<int> res = max_sliding_window(nums, k);
	for (auto i : res) {
		printf("%d ", i);
	}
	return EXIT_SUCCESS;
}