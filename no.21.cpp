#include <iostream>

using namespace std;

/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* list1, ListNode* list2) {
		ListNode* head = new ListNode(0);
		ListNode* now = head;
		while (list1 && list2) {
			if (list1->val > list2->val) {
				head->next = list2;
				list2 = list2->next;
			}
			else {
				head->next = list1;
				list1 = list1->next;
			}
			head = head->next;
		}
		if (list1 == NULL) {
			head->next = list2;
		}
		else if(list2 == NULL) {
			head->next = list1;
		}
		return now->next;
	}
};

int main() {
	system("pause");
	return 0;
}