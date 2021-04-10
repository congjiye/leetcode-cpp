#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == NULL) {
		return NULL;
	}
	ListNode* dummy = new ListNode(-1, head), *cur = dummy;
	while (cur->next && cur->next->next) {
		if (cur->next->val == cur->next->next->val) {
			cur->next = cur->next->next;
		}
		cur = cur->next;
	}
	return dummy->next;
}

int main() {
	ListNode node1(1);
	ListNode node2(1);
	ListNode node3(2);
	node1.next = &node2;
	node2.next = &node3;

	vector<int> input{ 1,1,2 };
	vector<int> output{ 1,2 };
	vector<int> result;
	ListNode* node = deleteDuplicates(&node1);
	while (node) {
		result.emplace_back(node->val);
		node = node->next;
	}
	assert(result == output);
	return EXIT_SUCCESS;
}