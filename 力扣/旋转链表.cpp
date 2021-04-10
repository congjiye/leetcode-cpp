#include <iostream>
#include <vector>
#include <cassert>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;
ListNode* rotateRight(ListNode* head, int k) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* p = head;
	int count_num = 1;
	while (p->next) {
		++count_num;
		p = p->next;
	}

	int x = k % count_num;
	if (!x) {
		return head;
	}
	ListNode* tail = p;
	p = head;
	for (int i = 0; i < count_num - x - 1; ++i) {
		p = p->next;
	}
	tail->next = head;
	ListNode* res = p->next;
	p->next = nullptr;
	return res;
}

int main() {
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);

	int count = 0;
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	vector<int> output{ 4,5,1,2,3 };
	vector<int> result;
	ListNode* node = rotateRight(&node1, 2);
	while (node) {
		result.emplace_back(node->val);
		node = node->next;
	}
	assert(output == result);
	return EXIT_SUCCESS;
}