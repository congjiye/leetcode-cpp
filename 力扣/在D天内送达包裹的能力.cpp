#include <bits/stdc++.h>

using namespace std;
int shipWithinDays(vector<int>& weights, int D) {
	int left = *max_element(weights.begin(), weights.end());
	int right = accumulate(weights.begin(), weights.end(), 0);

	while (left < right) {
		int mid = (left + right) / 2;

		int need = 1, cur = 0;
		for (int& weight : weights) {
			if (cur + weight > mid) {
				++need;
				cur = 0;
			}

			cur += weight;
		}

		if (need <= D) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return right;
}

int main() {
	vector<int> weights{ 1,2,3,4,5,6,7,8,9,10 };
	assert(shipWithinDays(weights, 5) == 15);
	return EXIT_SUCCESS;
}