#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace  std;

/*
��ʵ��һ����������֮����˳���ӡ������������һ�а��մ����ҵ�˳���ӡ���ڶ��㰴�մ��ҵ����˳���ӡ���������ٰ��մ����ҵ�˳���ӡ���������Դ����ơ�
*/

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) {
		val = x;
		left = NULL;
		right = NULL;
	}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL) {
			return res;
		}
		queue<TreeNode*> tree;
		tree.push(root);
		bool forward = true;
		while (!tree.empty()) {
			vector<int> mid;
			int length = tree.size();
			for (int i = 0; i < length; ++i) {
				TreeNode* now = tree.front();
				mid.push_back(now->val);
				if (now->left != NULL) {
					tree.push(now->left);
				}
				if (now->right != NULL) {
					tree.push(now->right);
				}
				tree.pop();
			}
			if (forward) {
				res.push_back(mid);
			}
			else {
				res.push_back(reverse(mid));
			}
			forward = !forward;
		}
		return res;
	}

	vector<int> reverse(vector<int> a) {
		vector<int> res;
		stack<int> mid;
		for (int i = 0; i < a.size(); ++i) {
			mid.push(a[i]);
		}
		for (int i = 0; i < a.size(); ++i) {
			res.push_back(mid.top());
			mid.pop();
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}