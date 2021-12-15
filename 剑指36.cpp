#include <iostream>
#include <vector>

using namespace std;

/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。

我们希望将这个二叉搜索树转化为双向循环链表。链表中的每个节点都有一个前驱和后继指针。对于双向循环链表，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。
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