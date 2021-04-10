#include <iostream>
#include <cassert>
#include <vector>
#include <deque>

using namespace std;
bool recur(vector<int>& postorder, int i, int j) {
	if (i >= j) {
		return true;
	}
	int p = i;
	while (postorder[p] < postorder[j]) {
		p++;
	}
	int m = p;
	while (postorder[p] > postorder[j]) {
		p++;
	}
	return p == j && recur(postorder, i, m - 1) && recur(postorder, m, j - 1);
}

bool verifyPostorder(vector<int>& postorder) {
	return recur(postorder, 0, postorder.size() - 1);
}

int main() {
	vector<int> input{ 1,6,3,2,5 };
	assert(verifyPostorder(input) == false);
	return EXIT_SUCCESS;
}