#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


struct ListNode {
	int val;
	ListNode *next;
    ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode * reverseEvenLengthGroups(ListNode* head) {
		if (head == NULL) {
			return NULL;
		}
		int now_len = 1;
		int bit = 0;
		ListNode* newhead = head;
		vector<int> vals;
		queue<ListNode*> nodes;
		while (newhead) {
			++bit;
			nodes.push(newhead);
			vals.push_back(newhead->val);
			if (bit == now_len || newhead->next == NULL) {
				if ((now_len % 2 == 0 && newhead->next != NULL) || (newhead->next == NULL && bit % 2 == 0)) {
					while (nodes.size() != 0) {
						ListNode* anode = nodes.front();
						anode->val = vals[vals.size() - 1];
						nodes.pop();
						vals.pop_back();
					}
				}
				vals.clear();
				while (nodes.size() != 0) {
					nodes.pop();
				}
				bit = 0;
				++now_len;
			}
			newhead = newhead->next;
		}
		return head;
	}
};

int main() {
	system("pause");
	return 0;
}