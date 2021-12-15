#include <iostream>
#include <vector>

using namespace std;

/*
0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。

例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
*/

class Solution {
public:
	int lastRemaining(int n, int m) {
		if (n == 0) {
			return 0;
		}
		return (lastRemaining(n - 1, m) + m) % n;
	}
	int lastRemaining_for(int n, int m) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res = (res + m) % i;
		}
		return res;
	}
};

int main() {
	int n, m;
	n = 5;
	m = 3;
	Solution s;
	int res = s.lastRemaining_for(n, m);
	cout << res << endl;
	system("pause");
	return 0;
}