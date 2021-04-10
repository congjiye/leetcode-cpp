#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	/*for (int i = m; i < nums2.size() + m; ++i) {
		nums1[i] = nums2[i - m];
	}

	sort(nums1.begin(), nums1.end());*/
	int mn = m + n;
	while (n) {
		if (m == 0 || nums1[m - 1] < nums2[n - 1]) {
			nums1[--mn] = nums2[--n];
		}
		else {
			nums1[--mn] = nums1[--m];
		}
	}
}

int main() {
	vector<int> nums1{ 1,2,3,0,0,0 };
	vector<int> nums2{ 2,5,6 };

	int m = 3, n = 3;
	merge(nums1, m, nums2, n);
	vector<int> result{ 1,2,2,3,5,6 };
	assert(nums1 == result);
	return EXIT_SUCCESS;
}