#include <bits/stdc++.h>

using namespace std;
int strStr(string haystack, string needle) {
	if (needle.empty()) {
		return 0;
	}

	int m = needle.size(), n = haystack.size();
	vector<int> next(m);

	next[0] = -1;
	int i = 0, j = -1;
	while (i < m - 1) {
		if (j == -1 || needle[i] == needle[j]) {
			next[++i] = ++j;
			continue;
		}
		j = next[j];
	}

	i = 0, j = 0;
	while (i < haystack.size() && j < m) {
		if (j == -1 || haystack[i] == needle[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}

	if (j == m) {
		return i - j;
	}
	return -1;
}

int main() {
	assert(strStr("Hello", "ll") == 2);
	return EXIT_SUCCESS;
}