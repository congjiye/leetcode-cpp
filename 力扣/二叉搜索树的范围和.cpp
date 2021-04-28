#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int rangeSumBST(TreeNode* root, int low, int high) {
	stack<TreeNode*> s;
	s.push(root);

	int sum = 0;
	while (!s.empty()) {
		TreeNode* node = s.top();
		s.pop();
		if (node->left && node->val >= low) {
			s.push(node->left);
		}

		if (node->val >= low && node->val <= high) {
			sum += node->val;
		}

		if (node->right && node->val <= high) {
			s.push(node->right);
		}
	}

	return sum;
}

int main() {
	int low = 7;
	int high = 15;

	TreeNode node1(10);
	TreeNode node2(5);
	TreeNode node3(15);
	TreeNode node4(3);
	TreeNode node5(7);
	TreeNode node6(18);

	node1.left = &node2;
	node2.left = &node4;
	node2.right = &node5;

	node1.right = &node3;
	node3.right = &node6;
	assert(rangeSumBST(&node1, low, high) == 32);
	return EXIT_SUCCESS;
}