#include <iostream>
#include <cassert>
#include <vector>
#include <deque>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* mirrorTree(TreeNode* root) {
	if (root == NULL) {
		return root;
	}

	TreeNode* left = mirrorTree(root->left);
	TreeNode* right = mirrorTree(root->right);
	root->left = right;
	root->right = left;
	return root;
}

int main() {
	TreeNode node1(4);
	TreeNode node2(2);
	TreeNode node3(7);
	TreeNode node4(1);
	TreeNode node5(3);
	TreeNode node6(6);
	TreeNode node7(9);

	node3.left = &node6;
	node3.right = &node7;
	node2.left = &node4;
	node2.right = &node5;

	node1.left = &node2;
	node1.right = &node3;

	TreeNode* node = mirrorTree(&node1);
	deque<TreeNode*> bfs;
	vector<int> res;
	bfs.push_back(node);
	while (!bfs.empty()) {
		if (bfs.front()->left) {
			bfs.push_back(bfs.front()->left);
		}

		if (bfs.front()->right) {
			bfs.push_back(bfs.front()->right);
		}

		res.emplace_back(bfs.front()->val);
		bfs.pop_front();
	}
	vector<int> ret{ 4,7,2,9,6,3,1 };
	assert(ret == res);
	return EXIT_SUCCESS;
}