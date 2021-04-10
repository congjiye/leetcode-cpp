#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;
string replaceSpace(string s) {
	stringstream ss;
	for (int i = 0; i < s.size(); ++i) {
		if (isspace(s.at(i))) {
			ss << "%20";
			continue;
		}
		ss << s.at(i);
	}
	return ss.str();
}

int main() {
	string s = "We are happy.";
	assert(replaceSpace(s) == "We%20are%20happy.");
	return EXIT_SUCCESS;
}