#include <iostream>

using namespace std;

/*
��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�
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