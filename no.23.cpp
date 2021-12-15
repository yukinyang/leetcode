#include <iostream>
#include <vector>

using namespace std;

/*
����һ���������飬ÿ�������Ѿ����������С�

���㽫��������ϲ���һ�����������У����غϲ��������
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