#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

	vector<vector<TreeNode*>> route;

	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		vector<TreeNode*> p_route;
		vector<TreeNode*> q_route;
		get_route(root, p, p_route);
		get_route(root, q, q_route);
		route[0].push_back(p);
		route[1].push_back(q);
		for (int i = 0; i < min(route[0].size(), route[1].size()); i++) {
			if (route[0][i] != route[1][i]) {
				return route[0][i - 1];
			}
		}
		return route[0][min(route[0].size(), route[1].size()) - 1];
	}

	void get_route(TreeNode* root, TreeNode* target, vector<TreeNode*>& nowroute) {
		if (root == nullptr) {
			// route.pop_back();
			return;
		}
		nowroute.push_back(root);
		if (root == target) {
			route.push_back(nowroute);
			return;
		}
		if (root->left) {
			get_route(root->left, target, nowroute);
		}
		if (root->right) {
			get_route(root->right, target, nowroute);
		}
		nowroute.pop_back();
		return;
	}
};

int main() {
	return 0;
}