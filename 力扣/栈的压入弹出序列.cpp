#include <iostream>
#include <cassert>
#include <vector>
#include <stack>

using namespace std;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	stack<int> q;
	int i = 0;
	for (int num : pushed) {
		q.push(num);
		while (!q.empty() && q.top() == popped[i]) {
			q.pop();
			++i;
		}
	}
	return q.empty();
}

int main() {
	vector<int> pushed{ 1,2,3,4,5 };
	vector<int> popped{ 4,5,3,2,1 };
	assert(validateStackSequences(pushed, popped));
	vector<int> popped2{ 4,3,5,1,2 };
	assert(validateStackSequences(pushed, popped2) == false);
	vector<int> pushed2{ 1, 0, 2, 3 };
	vector<int> popped3{ 1, 0, 2, 3 };
	assert(validateStackSequences(pushed2, popped3) == true);
	return EXIT_SUCCESS;
}