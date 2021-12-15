#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
	到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

	给定二叉树: [3,9,20,null,null,15,7],
			 3
			/ \
		   9  20
		 /  \
	   15   7

	返回其层次遍历结果：
	[
		[3],
		[9,20],
		[15,7]
	]
*/

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root) {
			return res;
		}
		queue<TreeNode*> tree;
		tree.push(root);
		while (!tree.empty()) {
			vector<int> mid;
			int len = tree.size();
			for (int i = 0; i < len; i++) {
				TreeNode* newroot = tree.back();
				if (newroot->left) {
					tree.push(newroot->left);
				}
				if (newroot->right) {
					tree.push(newroot->right);
				}
				mid.push_back(newroot->val);
				tree.pop();
			}
			res.push_back(mid);
		}
		return res;
	}
};

int main() {
	return 0;
}