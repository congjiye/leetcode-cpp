#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <deque>
#include <cassert>

using namespace std;
vector<int> levelOrder(TreeNode* root) {
	if (root == NULL) {
		return {};
	}
	deque<TreeNode*> bfs;
	vector<int> res;
	bfs.emplace_back(root);
	while (!bfs.empty()) {
		if (bfs.front()->left) {
			bfs.emplace_back(bfs.front()->left);
		}

		if (bfs.front()->right) {
			bfs.emplace_back(bfs.front()->right);
		}

		res.emplace_back(bfs.front()->val);
		bfs.pop_front();
	}
	return res;
}

int main() {
	vector<int> res{ 3,9,20,15,7 };
	TreeNode node1(3);
	TreeNode node2(9);
	TreeNode node3(20);
	TreeNode node4(15);
	TreeNode node5(7);

	node3.left = &node4;
	node3.right = &node5;

	node1.left = &node2;
	node1.right = &node3;

	vector<int> bfs = levelOrder(&node1);
	assert(bfs == res);
	return EXIT_SUCCESS;
}