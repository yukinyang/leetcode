#include <iostream>

using namespace std;

/*
泰波那契序列 Tn 定义如下： 

T0 = 0, T1 = 1, T2 = 1, 且在 n >= 0 的条件下 Tn+3 = Tn + Tn+1 + Tn+2

给你整数 n，请返回第 n 个泰波那契数 Tn 的值。
*/

class Solution {
public:
	int tribonacci(int n) {
		if (n <= 1) {
			return n;
		}
		if (n == 2) {
			return 1;
		}
		int ans;
		int fir = 0, sec = 1, trd = 1;
		for (int i = 3; i <= n; ++i) {
			ans = fir + sec + trd;
			fir = sec;
			sec = trd;
			trd = ans;
		}
		return ans;
	}
};