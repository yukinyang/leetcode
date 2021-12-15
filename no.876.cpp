#include <iostream>
#include <vector>

using namespace std;

/*
����һ��ͷ���Ϊ head �ķǿյ���������������м��㡣

����������м��㣬�򷵻صڶ����м��㡣
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