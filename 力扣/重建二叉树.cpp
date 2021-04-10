#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		for (int i = 0; i < inorder.size(); ++i) {
			dic_[inorder[i]] = i;
		}
		return rebuild(preorder, 0, 0, inorder.size() - 1);
	}

	TreeNode* rebuild(vector<int>& preorder, int root_index, int left_index, int right_index) {
		if (left_index > right_index) {
			return nullptr;
		}

		TreeNode* node = new TreeNode(preorder[root_index]);
		int i = dic_[preorder[root_index]];
		node->left = rebuild(preorder, root_index + 1, left_index, i - 1);
		node->right = rebuild(preorder, root_index + i - left_index + 1, i + 1, right_index);
		return node;
	}

private:
	unordered_map<int, int> dic_;
};

int main() {
	vector<int> preorder{ 3,9,20,15,7 };
	vector<int> inorder{ 9,3,15,20,7 };
	return EXIT_SUCCESS;
}