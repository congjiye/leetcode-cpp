#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;
int nthUglyNumber(int n) {
	vector<int> dp(n);
	dp[0] = 1;

	int p2 = 0, p3 = 0, p5 = 0;
	for (int i = 1; i < n; ++i) {
		int x2 = dp[p2] * 2, x3 = dp[p3] * 3, x5 = dp[p5] * 5;
		dp[i] = min(min(x2, x3), x5);
		if (dp[i] == x2) {
			++p2;
		}

		if (dp[i] == x3) {
			++p3;
		}

		if (dp[i] == x5) {
			++p5;
		}
	}

	return dp[n - 1];
}

int main() {
	assert(nthUglyNumber(10) == 12);
	return EXIT_SUCCESS;
}