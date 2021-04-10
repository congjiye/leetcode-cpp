#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteNode(ListNode* head, int val) {
	if (head->val == val) return head->next;
	ListNode *pre = head, *cur = head->next;
	while (cur != nullptr && cur->val != val) {
		pre = cur;
		cur = cur->next;
	}
	if (cur != nullptr) pre->next = cur->next;
	return head;
}

int main() {
	ListNode node1(4);
	ListNode node2(5);
	ListNode node3(1);
	ListNode node4(9);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;

	ListNode* head = deleteNode(&node1, 5);
	vector<int> ret{ 4, 1, 9 };
	vector<int> temp;
	while (head) {
		temp.emplace_back(head->val);
		head = head->next;
	}
	assert(temp == ret);
	return EXIT_SUCCESS;
}