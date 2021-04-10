#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
	if (matrix.size() == 0 || matrix[0].size() == 0) {
		return false;
	}

	int row = matrix.size() - 1;
	int col = 0;
	while (row >= 0 && col < matrix[0].size()) {
		if (target == matrix[row][col]) {
			return true;
		}

		if (target < matrix[row][col]) {
			row--;
		}
		else {
			col++;
		}
	}
	return false;
}

int main() {
	vector<vector<int>> matrix{
	{1,   4,  7, 11, 15},
	{2,   5,  8, 12, 19},
	{3,   6,  9, 16, 22},
	{10, 13, 14, 17, 24},
	{18, 21, 23, 26, 30}
	};
	assert(findNumberIn2DArray(matrix, 5) == true);
	assert(findNumberIn2DArray(matrix, 20) == false);

	vector<vector<int>> test{ {-1, 3} };
	cout << findNumberIn2DArray(test, -2);
	return EXIT_SUCCESS;
}