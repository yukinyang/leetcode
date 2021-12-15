#include <iostream>

using namespace std;

/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
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
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode* newhead = new ListNode(0);
		newhead->next = head;
		ListNode* p1 = newhead;
		ListNode* p2 = newhead;
		int i = 0;
		while (p1->next) {
			if (i == n) {
				p2 = p2->next;
			}
			else {
				++i;
			}
			p1 = p1->next;
		}
		p2->next = p2->next->next;
		return newhead->next;
	}
};