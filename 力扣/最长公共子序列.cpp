#include <bits/stdc++.h>

using namespace std;
int longestCommonSubsequence(string text1, string text2) {
	int n1 = text1.size();
	int n2 = text2.size();

	vector<vector<int>> dp(n2 + 1, vector<int>(n1 + 1));
	for (int i = 1; i <= n2; ++i) {
		char c1 = text2[i - 1];
		for (int j = 1; j <= n1; ++j) {
			if (text1[j - 1] == c1) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				continue;
			}

			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	return dp[n2][n1];
}

int main() {
	assert(longestCommonSubsequence("abcde", "ace") == 3);
	return EXIT_SUCCESS;
}