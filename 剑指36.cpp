#include <iostream>
#include <vector>

using namespace std;

/*
����һ�ö��������������ö���������ת����һ�������ѭ��˫������Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��

����ϣ�����������������ת��Ϊ˫��ѭ�����������е�ÿ���ڵ㶼��һ��ǰ���ͺ��ָ�롣����˫��ѭ��������һ���ڵ��ǰ�������һ���ڵ㣬���һ���ڵ�ĺ���ǵ�һ���ڵ㡣
*/

// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

class Solution {
public:
	vector<Node*> pre_list;
	Node * treeToDoublyList(Node* root) {
		if (root == NULL) {
			return NULL;
		}
		pre_list.resize(0);
		pre_trav(root);
		if (pre_list.size() == 1) {
			pre_list[0]->left = pre_list[0];
			pre_list[0]->right = pre_list[0];
			return pre_list[0];
		}
		for (int i = 0; i < pre_list.size(); ++i) {
			if (i == 0) {
				pre_list[i]->left = pre_list[pre_list.size() - 1];
				pre_list[i]->right = pre_list[i + 1];
			}
			else if (i == pre_list.size() - 1) {
				pre_list[i]->left = pre_list[i - 1];
				pre_list[i]->right = pre_list[0];
			}
			else {
				pre_list[i]->left = pre_list[i - 1];
				pre_list[i]->right = pre_list[i + 1];
			}
		}
		return pre_list[0];
	}

	void pre_trav(Node* root) {
		if (root == NULL) {
			return;
		}
		pre_trav(root->left);
		pre_list.push_back(root);
		pre_trav(root->right);
	}
};

int main() {
	system("pause");
	return 0;
}