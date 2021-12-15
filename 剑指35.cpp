#include <iostream>
#include  <vector>
#include <unordered_map>

using namespace std;

/*
��ʵ�� copyRandomList ����������һ�����������ڸ��������У�ÿ���ڵ������һ�� next ָ��ָ����һ���ڵ㣬����һ�� random ָ��ָ�������е�����ڵ���� null��
*/

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node * copyRandomList(Node* head) {
		/* hash_map */
		//if (head == NULL) {
		//	return NULL;
		//}
		//unordered_map<Node*, Node*> old_new;
		//Node* newhead = head;
		//Node* root = new Node(newhead->val);
		//Node* newroot = root;
		//while (newhead->next != NULL) {
		//	old_new[newhead] = newroot;
		//	Node* nextnode = new Node(newhead->next->val);
		//	newroot->next = nextnode;
		//	newroot = newroot->next;
		//	newhead = newhead->next;
		//}
		//old_new[newhead] = newroot;
		//newroot = root;
		//newhead = head;
		//while (newroot != NULL) {
		//	if (newhead->random != NULL) {
		//		newroot->random = old_new[newhead->random];
		//	}
		//	newroot = newroot->next;
		//	newhead = newhead->next;
		//}
		//return root;

		/* ����������ƴ�� */
		if (head == NULL) {
			return NULL;
		}
		Node* newhead = head;
		while (newhead != NULL) {
			Node* newone = new Node(newhead->val);
			newone->next = newhead->next;
			newone->random = newhead->random;
			newhead->next = newone;
			newhead = newhead->next->next;
		}
		newhead = head;
		while (newhead != NULL) {
			if (newhead->random != NULL) {
				newhead->next->random = newhead->random->next;
			}
			newhead = newhead->next->next;
		}
		newhead = head;
		Node* res = head->next;
		Node* newres = head->next;
		while (newhead->next != NULL) {
			newhead->next = newhead->next->next;
			newres->next = newres->next->next;
			newhead = newhead->next;
			newres = newres->next;
		}
		newhead->next = nullptr;        //  ���ܸ���ԭ��������Ҫ������һ��
		return res;
	}
};

int main() {
	return 0;
}