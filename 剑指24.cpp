#include <iostream>
#include <stack>

using namespace std;

/*
����һ������������һ�������ͷ�ڵ㣬��ת�����������ת�������ͷ�ڵ㡣
*/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverseList(ListNode* head) {
		ListNode* newhead = new ListNode(0);
		stack<ListNode*> stk;
		stk.push(NULL);
		while (head) {
			stk.push(head);
			head = head->next;
		}
		ListNode* nowhead = newhead;
		while (stk.size()) {
			newhead->next = stk.top();
			stk.pop();
			newhead = newhead->next;
		}
		return nowhead->next;
	}
};