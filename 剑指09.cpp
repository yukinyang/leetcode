#include <iostream>
#include <stack>

using namespace std;

/*
用两个栈实现一个队列。

队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead 。

分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )
*/

class CQueue {
public:
	stack<int> a; // a 用来出栈
	stack<int> b; // b 用来进栈
	CQueue() {
		
	}

	void appendTail(int value) {
		b.push(value);
	}

	int deleteHead() {
		if (!a.size()) {
			while (b.size()) {
				a.push(b.top());
				b.pop();
			}
		}
		int ans = -1;
		if (a.size()) {
			ans = a.top();
			a.pop();
		}
		return  ans;
	}
};

/**
* Your CQueue object will be instantiated and called as such:
* CQueue* obj = new CQueue();
* obj->appendTail(value);
* int param_2 = obj->deleteHead();
*/