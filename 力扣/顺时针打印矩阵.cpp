#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
	if (matrix.empty()) {
		return {};
	}

	int l = 0;
	int r = matrix[0].size() - 1;
	int t = 0;
	int b = matrix.size() - 1;

	vector<int> res;
	while (true) {
		for (int i = l; i <= r; ++i) {
			res.emplace_back(matrix[t][i]);
		}
		if (++t > b) {
			break;
		}

		for (int i = t; i <= b; ++i) {
			res.emplace_back(matrix[i][r]);
		}
		if (--r < l) {
			break;
		}

		for (int i = r; i >= l; --i) {
			res.emplace_back(matrix[b][i]);
		}
		if (--b < t) {
			break;
		}

		for (int i = b; i >= t; --i) {
			res.emplace_back(matrix[i][l]);
		}
		if (++l > r) {
			break;
		}
	}
	return res;
}

int main() {
	vector<vector<int>> matrix = {
	{1,2,3},
	{4,5,6},
	{7,8,9}
	};
	vector<int> res = spiralOrder(matrix);
	vector<int> compare = { 1,2,3,6,9,8,7,4,5 };
	assert(res == compare);
	return EXIT_SUCCESS;
}