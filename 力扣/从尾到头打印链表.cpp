#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL){}
};

vector<int> reversePrint(ListNode* head) {
	vector<int> temp;
	while (head != NULL) {
		temp.emplace_back(head->val);
		head = head->next;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}

int main() {
	ListNode node1(1);
	ListNode node2(3);
	ListNode node3(2);
	node2.next = &node3;
	node1.next = &node2;

	ListNode* head = &node1;
	vector<int> res{ 2, 3, 1 };
	assert(res == reversePrint(head));
	return EXIT_SUCCESS;
}