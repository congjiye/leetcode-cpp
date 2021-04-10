#include "TreeNode.h"
#include <iostream>
#include <deque>
#include <cassert>
#include <vector>

using namespace std;
bool recur(TreeNode* left, TreeNode* right) {
	if (left == NULL && right == NULL) {
		return true;
	}

	if (left == NULL || right == NULL) {
		return false;
	}

	if (left->val != right->val) {
		return false;
	}

	return recur(left->left, right->right) && recur(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
	return recur(root->left, root->right);
}

int main() {
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(2);
	TreeNode node4(3);
	TreeNode node5(4);
	TreeNode node6(4);
	TreeNode node7(3);

	node2.left = &node4;
	node2.right = &node5;

	node3.left = &node6;
	node3.right = &node7;

	node1.left = &node2;
	node1.right = &node3;

	vector<int> result;
	deque<TreeNode> bfs;
	bfs.emplace_back(node1);
	while (!bfs.empty()) {
		if (bfs.front().left) {
			bfs.push_back(*bfs.front().left);
		}

		if (bfs.front().right) {
			bfs.push_back(*bfs.front().right);
		}

		result.emplace_back(bfs.front().val);
		bfs.pop_front();
	}

	for (int i : result) {
		cout << i << " ";
	}

	assert(isSymmetric(&node1));
	return EXIT_SUCCESS;
}