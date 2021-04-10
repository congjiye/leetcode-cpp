#include <iostream>
#include <vector>
#include <cassert>
#include <stack>

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
	BSTIterator(TreeNode* root) {
		i = 0;
		inorder(root);
	}

	void inorder(TreeNode* root) {
		if (root->left) {
			inorder(root->left);
		}
		v.emplace_back(root->val);
		if (root->right) {
			inorder(root->right);
		}
	}

	void inorderNR(TreeNode* root) {
		TreeNode* cur = root;
		stack<TreeNode*> s;
		while (cur || !s.empty()) {
			while (cur) {
				s.push(cur);
				cur = cur->left;
			}

			if (!s.empty()) {
				TreeNode* r = s.top();
				s.pop();
				v.push_back(r->val);
				cur = cur->right;
			}
		}
	}

	int next() {
		return v[i++];
	}

	bool hasNext() {
		return i < v.size();
	}

private:
	vector<int> v;
	int i;
};

int main() {
	TreeNode node(7);
	BSTIterator* iter = new BSTIterator(&node);
	int param_1 = iter->next();
	bool param_2 = iter->hasNext();
	return EXIT_SUCCESS;
}