#include <iostream>

using namespace std;

/*
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:
          3
	     / \
	   4   5
     / \
    1   2
给定的树 B：
	     4 
	   /
     1
返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSubStructure(TreeNode* A, TreeNode* B) {
		return bianli(A, B);
	}

	bool bianli(TreeNode* A, TreeNode* B) {
		if (A == NULL || B == NULL) {
			return false;
		}
		if (A->val == B->val) {
			if (BinA(A, B)) {
				return true;
			}
		}
		return bianli(A->left, B) || bianli(A->right, B);
	}

	bool BinA(TreeNode* A, TreeNode* B) {
		if (B == NULL) {
			return true;
		}
		if (A == NULL) {
			return false;
		}
		if (A->val == B->val) {
			return BinA(A->left, B->left) && BinA(A->right, B->right);
		}
		return false;
	}
};

int main() {
	system("pause");
	return 0;
}