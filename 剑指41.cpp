#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

/*
如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

例如，

[2,3,4] 的中位数是 3

[2,3] 的中位数是 (2 + 3) / 2 = 2.5

设计一个支持以下两种操作的数据结构：

void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。
*/

/*用vector每次排序去中位数会超时*/

class MedianFinder {
public:
	/** initialize your data structure here. */
	priority_queue< int, vector<int>, less<int> > small; /*大顶堆放小数据*/
	priority_queue< int, vector<int>, greater<int> > big;/*小顶堆放大数据*/
	MedianFinder() {
		
	}

	void addNum(int num) {
		if (small.size() == big.size()) {
			small.push(num);
			big.push(small.top());
			small.pop();
		}
		else {
			big.push(num);
			small.push(big.top());
			big.pop();
		}
	}

	double findMedian() {
		if (small.size() == big.size()) {
			return double(small.top() + big.top()) / 2.0;
		}
		else {
			return double(big.top());
		}
	}
};

int main() {
	system("pause");
	return 0;
}