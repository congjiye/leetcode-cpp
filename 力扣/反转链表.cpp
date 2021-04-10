#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
	ListNode* pre = NULL, *cur = head;
	while (cur) {
		ListNode* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	return pre;
}

int main() {
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	ListNode* reverse_node = reverseList(&node1);
	vector<int> compare{ 5, 4, 3, 2, 1 };
	vector<int> result;
	while (reverse_node) {
		result.emplace_back(reverse_node->val);
		reverse_node = reverse_node->next;
	}
	assert(result == compare);
	return EXIT_SUCCESS;
}