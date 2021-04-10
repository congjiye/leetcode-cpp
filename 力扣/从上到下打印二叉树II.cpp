#include "TreeNode.h"
#include <iostream>
#include <vector>
#include <deque>
#include <cassert>

using namespace std;
vector<vector<int>> levelOrder(TreeNode* root) {
	if (root == NULL) {
		return {};
	}
	vector<vector<int>> res;
	deque<TreeNode*> bfs;
	bfs.emplace_back(root);
	while (!bfs.empty()) {
		vector<int> temp;
		for (int i = bfs.size(); i > 0; --i) {
			temp.emplace_back(bfs.front()->val);
			if (bfs.front()->left) {
				bfs.emplace_back(bfs.front()->left);
			}

			if (bfs.front()->right) {
				bfs.emplace_back(bfs.front()->right);
			}
			bfs.pop_front();
		}
		res.emplace_back(temp);
	}
	return res;
}

int main() {
	vector<vector<int>> res{ {3},{9,20},{15,7} };
	TreeNode node1(3);
	TreeNode node2(9);
	TreeNode node3(20);
	TreeNode node4(15);
	TreeNode node5(7);

	node3.left = &node4;
	node3.right = &node5;

	node1.left = &node2;
	node1.right = &node3;

	vector<vector<int>> bfs = levelOrder(&node1);
	assert(bfs == res);
	return EXIT_SUCCESS;
}