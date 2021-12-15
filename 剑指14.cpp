#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。

请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/

class Solution {
public:
	int cuttingRope(int n) {
		int res = 1;
		if (n == 2) {
			return 1;
		}
		if (n == 3) {
			return 2;
		}
		if (n == 4) {
			return 4;
		}
		switch (n % 3) {
		case 0:
			while (n) {
				res = (res * 3) % 1000000007;
				n -= 3;
			}
			break;
		case 1:
			n -= 4;
			while (n) {
				res = (res * 3) % 1000000007;
				n -= 3;
			}
			res = (res * 4) % 1000000007;
			break;
		case 2:
			n -= 2;
			while (n) {
				res = (res * 3) % 1000000007;
				n -= 3;
			}
			res = (res * 2) % 1000000007;
			break;
		}
		return (int)res;
	}
};

int main() {
	Solution s;
	cout << s.cuttingRope(1000) << endl;
	system("pause");
	return 0;
}