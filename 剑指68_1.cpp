#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) {
			return nullptr;
		}
		TreeNode* p1 = root;
		TreeNode* q1 = root;
		vector<TreeNode*> proute;
		vector<TreeNode*> qroute;
		while (p1 != p) {
			proute.push_back(p1);
			if (p1->val > p->val) {
				p1 = p1->left;
			}
			else {
				p1 = p1->right;
			}
		}
		while (q1 != q) {
			qroute.push_back(q1);
			if (q1->val > q->val) {
				q1 = q1->left;
			}
			else {
				q1 = q1->right;
			}
		}
		// cout << proute.size() << endl;
		// cout << qroute.size() << endl;
		int num = 0;
		while (num < min(proute.size(), qroute.size()) && proute[num] == qroute[num]) {
			num++;
		}
		return proute[num - 1];
		// return root;
	}
};

int main() {
	return 0;
}