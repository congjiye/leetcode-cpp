#include <iostream>
#include <string>

using namespace std;
string reverse_left_words(string s, int n) {
	if (n < 1 || n > 10000) {
		return "";
	}

	return s.substr(n) + s.substr(0, n);
}

int main() {
	string s = "abcdefg";
	int k = 2;
	cout << reverse_left_words(s, k) << endl;
	return EXIT_SUCCESS;
}