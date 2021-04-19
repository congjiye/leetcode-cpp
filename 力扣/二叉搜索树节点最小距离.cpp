#include <iostream>
#include <vector>
#include <cassert>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* pre = nullptr;
void recur(TreeNode* root, int& min) {
	if (!root) {
		return;
	}

	if (root->left) {
		recur(root->left, min);
	}

	if (pre && (min > root->val - pre->val)) {
		min = root->val - pre->val;
	}

	pre = root;
	if (root->right) {
		recur(root->right, min);
	}
}

int minDiffInBST(TreeNode* root) {
	int min = 1e5 + 1;
	recur(root, min);
	return min;
}

int main() {
	TreeNode node1(4);
	TreeNode node2(2);
	TreeNode node3(6);
	TreeNode node4(1);
	TreeNode node5(3);

	node2.left = &node4;
	node2.right = &node5;

	node1.left = &node2;
	node1.right = &node3;
	assert(minDiffInBST(&node1) == 1);
	return EXIT_SUCCESS;
}