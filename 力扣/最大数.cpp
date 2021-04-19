#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
string largestNumber(vector<int>& nums) {	
	string res;
	vector<string> temp;
	for (auto& num : nums) {
		temp.emplace_back(to_string(num));
	}

	sort(temp.begin(), temp.end(), [](string a, string b) {
		return a + b > b + a;
	});
	for (auto& t : temp) {
		res += t;
	}

	if (res[0] == '0') {
		return "0";
	}
	return res;
}

int main() {
	vector<int> nums{ 10, 2 };
	assert(largestNumber(nums) == "210");
	return EXIT_SUCCESS;
}