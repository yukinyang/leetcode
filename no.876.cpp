#include <iostream>
#include <vector>

using namespace std;

/*
给定一个头结点为 head 的非空单链表，返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。
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
	ListNode * middleNode(ListNode* head) {
		vector<ListNode*> list;
		while (head) {
			list.push_back(head);
			head = head->next;
		}
		int n = list.size();
		return n % 2 ? list[n / 2 + 1] : list[n / 2];
	}
};