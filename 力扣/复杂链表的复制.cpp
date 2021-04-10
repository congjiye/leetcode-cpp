#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

Node* copyRandomList(Node* head) {
	if (!head) {
		return nullptr;
	}

	unordered_map<Node*, Node*> map;
	Node* cur = head;
	while (cur) {
		map[cur] = new Node(cur->val);
		cur = cur->next;
	}

	cur = head;
	while (cur) {
		map[cur]->next = map[cur->next];
		map[cur]->random = map[cur->random];
		cur = cur->next;
	}
	return map[head];
}

int main() {
	vector<vector<int>> input{ {1,1}, {2,1} };
	vector<vector<int>> output;
	Node node1(1);
	Node node2(2);

	node1.random = &node2;
	node1.next = &node2;

	node2.random = &node2;

	Node* res = copyRandomList(&node1);
	while (res) {
		vector<int> temp;
		temp.push_back(res->val);
		temp.push_back(res->random->val);
		output.emplace_back(temp);
		res = res->next;
	}
	assert(input == output);
	return EXIT_SUCCESS;
}