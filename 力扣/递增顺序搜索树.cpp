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

TreeNode* increasingBST(TreeNode* root) {
	if (root == nullptr) {
		return nullptr;
	}

	stack<TreeNode*> st;
	st.push(root);

	TreeNode* head = new TreeNode(-1), *cur = head;
	while (!st.empty()) {
		if (root->left) {
			st.push(root->left);
			root = root->left;
		}

		TreeNode* node = st.top();
		st.pop();
		cur->right = new TreeNode(node->val);
		cur = node;

		if (node->right) {
			st.push(node->right);
			root = node->right;
		}
	}

	return head->right;
}

int main() {
	return EXIT_SUCCESS;
}