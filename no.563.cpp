#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

/*
����һ�������������� ������ ���¶� ��

һ������ �ڵ���¶� ���弴Ϊ���ýڵ��������Ľڵ�֮�ͺ��������ڵ�֮�͵� ��ľ���ֵ ��

���û���������Ļ����������Ľڵ�֮��Ϊ 0 ��û���������Ļ�Ҳ��һ�����ս����¶��� 0 ��

������ ���¶Ⱦ��������нڵ���¶�֮�͡�
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