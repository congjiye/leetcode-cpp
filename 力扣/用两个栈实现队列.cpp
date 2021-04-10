#include <iostream>
#include <stack>

using namespace std;

class CQueue {
public:
	CQueue() {
		first_ = {};
		second_ = {};
	}

	void appendTail(int value) {
		first_.push(value);
	}

	int deleteHead() {
		if (second_.empty() && first_.empty()) {
			return -1;
		}

		if (second_.empty() && first_.size() == 1) {
			int ret = first_.top();
			first_.pop();
			return ret;
		}

		while (second_.empty()) {
			while (!first_.empty()) {
				second_.push(first_.top());
				first_.pop();
			}
		}

		int ret = second_.top();
		second_.pop();
		return ret;
	}

private:
	stack<int> first_;
	stack<int> second_;
};

int main() {
	CQueue cqueue;
	return EXIT_SUCCESS;
}