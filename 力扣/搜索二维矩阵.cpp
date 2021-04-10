#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	if (matrix.empty() || matrix[0].empty()) {
		return false;
	}
	int row = matrix.size() - 1;
	int col = 0;
	while (row >= 0 && col < matrix[0].size()) {
		if (matrix[row][col] > target) {
			--row;
		} else if (matrix[row][col] < target) {
			++col;
		} else {
			return true;
		}
	}
	return false;
}

int main() {
	//vector<vector<int>> matrix{ {1,3,5,7},{10,11,16,20},{23,30,34,60} };
	vector<vector<int>> matrix{ {1, 3} };
	assert(searchMatrix(matrix, 3));
	return EXIT_SUCCESS;
}