#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一棵 二叉树 的根节点 root ，这棵二叉树总共有 n 个节点。每个节点的值为 1 到 n 中的一个整数，且互不相同。
给你一个整数 startValue ，表示起点节点 s 的值，和另一个不同的整数 destValue ，表示终点节点 t 的值。

请找到从节点 s 到节点 t 的 最短路径 ，并以字符串的形式返回每一步的方向。每一步用 大写 字母 'L' ，'R' 和 'U' 分别表示一种方向：

'L' 表示从一个节点前往它的 左孩子 节点。
'R' 表示从一个节点前往它的 右孩子 节点。
'U' 表示从一个节点前往它的 父 节点。
请你返回从 s 到 t 最短路径 每一步的方向。
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
	vector<TreeNode*> st_route;
	vector<TreeNode*> de_route;
	string getDirections(TreeNode* root, int startValue, int destValue) {
		string ans = "";
		vector<TreeNode*> route;
		get_route(root, route, startValue, destValue);
		TreeNode* pubnode;
		int i = 0;
		while (i < min(st_route.size(), de_route.size()) && st_route[i] == de_route[i]) {
			++i;
		}
		pubnode = st_route[i - 1];
		for (int x = 0; x < st_route.size() - i; ++x) {
			ans += "U";
		}
		for (int x = 0; x < de_route.size() - i; ++x) {
			if (pubnode->left == de_route[i + x]) {
				ans += "L";
			}
			else {
				ans += "R";
			}
			pubnode = de_route[i + x];
		}
		return ans;
	}

	void get_route(TreeNode* root, vector<TreeNode*>& route, int startValue, int destValue) {
		if (root == NULL) {
			return;
		}
		route.push_back(root);
		if (root->val == startValue) {
			st_route = route;
		}
		if (root->val == destValue) {
			de_route = route;
		}
		get_route(root->left, route, startValue, destValue);
		get_route(root->right, route, startValue, destValue);
		route.pop_back();
	}
};

int main() {
	system("pause");
	return 0;
}