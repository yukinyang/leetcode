#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
*/

class MinStack {
public:
	/** initialize your data structure here. */
	vector<int> nmin;
	vector<int> nums;
	MinStack() {

	}

	void push(int x) {
		nums.push_back(x);
		if (nmin.size()) {
			if (nmin[nmin.size() - 1] >= x) {
				nmin.push_back(x);
			}
			else {
				nmin.push_back(nmin[nmin.size() - 1]);
			}
		}
		else {
			nmin.push_back(x);
		}
	}

	void pop() {
		nums.pop_back();
		nmin.pop_back();
	}

	int top() {
		return nums[nums.size() - 1];
	}

	int min() {
		return nmin[nmin.size() - 1];
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->min();
*/