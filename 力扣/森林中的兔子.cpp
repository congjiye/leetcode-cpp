#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
int numRabbits(vector<int>& answers) {
	if (answers.empty()) {
		return 0;
	}

	unordered_map<int, int> m;
	int count = 0;
	for (int i = 0; i < answers.size(); ++i) {
		if (m[answers[i]] == 0) {
			count += (answers[i] + 1);
			m[answers[i]] = answers[i];
			continue;
		}

		m[answers[i]] -= 1;
	}

	return count;
}

int main() {
	vector<int> answers{ 1,1,2 };
	assert(numRabbits(answers) == 5);
	return EXIT_SUCCESS;
}