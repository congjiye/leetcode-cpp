#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode* node = new ListNode(0);
	ListNode* res = node;
	while (l1 && l2) {
		if (l1->val <= l2->val) {
			node->next = l1;
			l1 = l1->next;
		}
		else {
			node->next = l2;
			l2 = l2->next;
		}
		node = node->next;
	}

	if (l1) {
		node->next = l1;
	}

	if (l2) {
		node->next = l2;
	}
	return res->next;
}

int main() {
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(4);

	node1.next = &node2;
	node2.next = &node3;

	ListNode node4(1);
	ListNode node5(3);
	ListNode node6(4);

	node4.next = &node5;
	node5.next = &node6;

	vector<int> result;
	vector<int> compare{ 1,1,2,3,4,4 };
	ListNode* node = mergeTwoLists(&node1, &node4);
	while (node) {
		result.emplace_back(node->val);
		node = node->next;
	}
	assert(result == compare);
	return EXIT_SUCCESS;
}