#include <iostream>
#include <queue>
#include <deque>

using namespace std;

/*
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。

若队列为空，pop_front 和 max_value 需要返回 -1
*/

class MaxQueue {
public:
	queue<int> q;
	deque<int> qmax;
	MaxQueue() {

	}

	int max_value() {
		if (q.empty()) {
			return -1;
		}
		else {
			return qmax.front();
		}
	}

	void push_back(int value) {
		q.push(value);
		if (q.empty()) {
			qmax.push_back(value);
		}
		else if (qmax.front() < value) {
			qmax.clear();
			qmax.push_back(value);
		}
		else {
			while (qmax.back() < value) {
				qmax.pop_back();
			}
			qmax.push_back(value);
		}
	}

	int pop_front() {
		if (q.empty()) {
			return -1;
		}
		else {
			int res = q.front();
			q.pop();
			if (qmax.front() == res) {
				qmax.pop_front();
			}
			return res;
		}
	}
};

int main() {
	MaxQueue m;
	m.push_back(1);
	m.push_back(2);
	int a = m.max_value();
	int b = m.pop_front();
	int c = m.max_value();
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	system("pause");
	return 0;
}