#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
给定一个二叉树，计算 整个树 的坡度 。

一个树的 节点的坡度 定义即为，该节点左子树的节点之和和右子树节点之和的 差的绝对值 。

如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。空结点的坡度是 0 。

整个树 的坡度就是其所有节点的坡度之和。
*/

struct TreeNode {
	int val;
	TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	int res;
	int findTilt(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		get_val(root);
		return res;
	}

	void get_val(TreeNode* root) {
		if (root == NULL) {
			return;
		}
		int l = 0, r = 0;
		l = get_all(root->left);
		r = get_all(root->right);
		res += abs(l - r);
		get_val(root->left);
		get_val(root->right);
	}

	int get_all(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		return root->val + get_all(root->left) + get_all(root->right);
	}
};

int main() {
	system("pause");
	return 0;
}