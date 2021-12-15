#include <iostream>

using namespace std;

/*
斐波那契数，通常用 F(n) 表示，形成的序列称为 斐波那契数列 。该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。

给你 n ，请计算 F(n)。
*/

class Solution {
public:
	int fib(int n) {
		if (n <= 1) {
			return n;
		}
		int ans;
		int fir = 0, sec = 1;
		for (int i = 2; i <= n; ++i) {
			ans = (fir + sec);
			fir = sec;
			sec = ans;
		}
		return ans;
	}
};