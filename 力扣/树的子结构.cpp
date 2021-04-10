#include "TreeNode.h"
#include <iostream>

using namespace std;
bool isSubStructure(TreeNode* A, TreeNode* B) {
	if (A == NULL || B == NULL) {
		return false;
	}
	return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
}

bool recur(TreeNode* A, TreeNode* B) {
	if (B == NULL) {
		return true;
	}
	if (A == NULL || A->val != B->val) {
		return false;
	}

	return recur(A->left, B->left) && recur(A->right, B->right);
}

int main() {
	return EXIT_SUCCESS;
}