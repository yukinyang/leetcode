#include <iostream>
#include <vector>

using namespace std;

/*
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。
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
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) {
			return NULL;
		}
		ListNode* ans = lists[0];
		for (int i = 1; i < lists.size(); ++i) {
			ans = merge(ans, lists[i]);
		}
		return ans;
	}

	ListNode* merge(ListNode* a, ListNode* b) {
		ListNode* ans = new ListNode();
		ListNode* now = ans;
		while (a && b) {
			if (a->val > b->val) {
				ans->next = b;
				b = b->next;
			}
			else {
				ans->next = a;
				a = a->next;
			}
		}
		if (a == NULL) {
			now->next = b;
		}
		else {
			now->next = a;
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}