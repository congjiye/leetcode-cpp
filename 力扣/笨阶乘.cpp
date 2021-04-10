#include <iostream>
#include <cassert>
#include <stack>

using namespace std;
int clumsy(int N) {
	stack<int> s1;
	s1.push(N);
	N--;

	int index = 0;
	while (N > 0) {
		if (index % 4 == 0) {
			int temp = s1.top();
			s1.pop();
			s1.push(temp * N);
		}
		else if (index % 4 == 1) {
			int temp = s1.top();
			s1.pop();
			s1.push(temp / N);
		}
		else if (index % 4 == 2) {
			s1.push(N);
		}
		else {
			s1.push(-N);
		}
		--N;
		++index;
	}
	int sum = 0;
	while (!s1.empty()) {
		sum += s1.top();
		s1.pop();
	}
	return sum;
}

int main() {
	assert(clumsy(4) == 7);
	return EXIT_SUCCESS;
}