#include <iostream>
#include <cassert>
#include <string>
#include <unordered_map>

using namespace std;
unordered_map<string, bool> memo;
bool isScramble(string s1, string s2) {
	string s = s1 + ":" + s2;
	if (memo.count(s)) return memo[s];
	if (s1 == s2) return memo[s] = true;
	int n = s1.size();
	for (int i = 1; i < n; ++i) {
		string xl = s1.substr(0, i), xr = s2.substr(0, i), yl = s1.substr(i), yr = s2.substr(i);
		bool res1 = isScramble(xl, xr) && isScramble(yl, yr);
		xl = s1.substr(0, i), xr = s2.substr(n - i), yl = s1.substr(i), yr = s2.substr(0, n - i);
		bool res2 = isScramble(xl, xr) && isScramble(yl, yr);
		if (res1 || res2) return memo[s] = true;
	}

	return memo[s] = false;
}

int main() {
	assert(isScramble("a", "a"));
	assert(isScramble("abcde", "caebd") == false);
	assert(isScramble("abcdbdacbdac", "bdacabcdbdac"));
	assert(isScramble("abb", "bba"));
	return EXIT_SUCCESS;
}