#include <iostream>
#include  <vector>
#include <unordered_map>

using namespace std;

/*
请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
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

		/* 复制链表再拼接 */
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
		newhead->next = nullptr;        //  不能更改原链表，所以要加上这一句
		return res;
	}
};

int main() {
	return 0;
}