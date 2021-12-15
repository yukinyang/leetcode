#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���
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