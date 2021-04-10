#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int numWays(int n) {
	if (n == 0) {
		return 1;
	}

	vector<int> dp(n + 1);
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i <= n; ++i) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 1000000007;
	}
	return dp[n];
}

int main() {
	assert(numWays(2) == 2);
	assert(numWays(7) == 21);
	return EXIT_SUCCESS;
}