#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
int trap(vector<int>& height) {
	int volume = accumulate(height.begin(), height.end(), 0);
	int sum = 0, level = 1;
	int left = 0, right = height.size() - 1;
	while (left <= right) {
		while (left <= right && height[left] < level) {
			++left;
		}

		while (left <= right && height[right] < level) {
			--right;
		}

		sum += (right - left + 1);
		++level;
	}

	return sum - volume;
}

int main() {
	vector<int> height{ 0,1,0,2,1,0,1,3,2,1,2,1 };
	assert(trap(height) == 6);
	return EXIT_SUCCESS;
}