#include <iostream>
#include <cassert>
#include <vector>

using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getKthFromEnd(ListNode* head, int k) {
	ListNode* first = head;
	ListNode* second = head;
	for (int i = 0; i < k; ++i) {
		first = first->next;
	}
	while (first) {
		first = first->next;
		second = second->next;
	}
	return second;
}

int main() {
	vector<int> input{ 4, 5 };
	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);
	ListNode node5(5);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	ListNode* root = getKthFromEnd(&node1, 2);
	vector<int> res;
	while (root) {
		res.emplace_back(root->val);
		root = root->next;
	}
	assert(res == input);
	return EXIT_SUCCESS;
}