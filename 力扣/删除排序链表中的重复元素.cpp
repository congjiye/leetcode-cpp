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
	ListNode* node = new ListNode(0, head), *cur = node;
	while (cur->next && cur->next->next) {
		if (cur->next->val == cur->next->next->val) {
			int x = cur->next->val;
			while (cur->next && cur->next->val == x) {
				cur->next = cur->next->next;
			}
		}
		else {
			cur = cur->next;
		}
	}
	return node->next;
}

int main() {
	ListNode node1(1);
	ListNode node2(1);
	ListNode node3(1);
	ListNode node4(2);
	ListNode node5(3);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	vector<int> input{ 1,1,1,2,3 };
	vector<int> output{ 2,3 };
	vector<int> result;

	ListNode* node = deleteDuplicates(&node1);
	while (node) {
		result.emplace_back(node->val);
		node = node->next;
	}
	assert(output == result);
	return EXIT_SUCCESS;
}