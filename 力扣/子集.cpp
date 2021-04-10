#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
	vector<vector<int>> res{ {} };
	for (auto num : nums) {
		vector<vector<int>> temp = res;
		for (int i = 0; i < temp.size(); ++i) {
			vector<int> sub = temp[i];
			sub.emplace_back(num);
			res.emplace_back(sub);
		}
	}
	return res;
}

int main() {
	vector<int> input{ 1,2,3 };
	vector<vector<int>> result{ {}, {1},{2}, {1,2},{3},{1,3},{2,3},{1,2,3} };
	vector<vector<int>> output = subsetsWithDup(input);
	assert(result == output);
	return EXIT_SUCCESS;
}