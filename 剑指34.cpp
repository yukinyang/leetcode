#include <iostream>
#include <vector>

using namespace std;

/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。

叶子节点 是指没有子节点的节点。
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
	vector<vector<int>> res;
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		if (root == NULL) {
			return res;
		}
		vector<int> nowvec;
		get_res(root, 0, target, nowvec);
		return res;
	}

	void get_res(TreeNode* root, int now, int target, vector<int> nowvec) {
		if (root->left == NULL && root->right == NULL) {
			now += root->val;
			nowvec.push_back(root->val);
			cout << now << endl;
			if (now == target) {
				res.push_back(nowvec);
			}
			now -= root->val;
			nowvec.pop_back();
			return;
		}
		now += root->val;
		nowvec.push_back(root->val);
		if (root->left) {
			get_res(root->left, now, target, nowvec);
		}
		if (root->right) {
			get_res(root->right, now, target, nowvec);
		}
	}
};

int main() {
	system("pause");
	return 0;
}