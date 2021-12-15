#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> reversePrint(ListNode* head) {
		vector<int> ans;
		stack<ListNode*> stk;
		while (head) {
			stk.push(head);
			head = head->next;
		}
		while (stk.size()) {
			ans.push_back(stk.top()->val);
			stk.pop();
		}
		return ans;
	}
};