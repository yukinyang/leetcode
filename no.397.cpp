#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个正整数 n ，你可以做如下操作：

如果 n 是偶数，则用 n / 2替换 n 。
如果 n 是奇数，则可以用 n + 1或n - 1替换 n 。
n 变为 1 所需的最小替换次数是多少？
*/

class Solution {
public:
	int integerReplacement(int n) {
		/* dp超时 */
		//vector<int> dp(n + 1, 0);
		//dp[1] = 0;
		//for (int i = 2; i <= n; ++i) {
		//	if (i % 2 == 0) {
		//		dp[i] = dp[i / 2] + 1;
		//	}
		//	else {
		//		dp[i] = min(dp[i / 2], dp[i / 2 + 1]) + 2;
		//	}
		//}
		//return dp[n];

		/* 递归 */
		if (n == 1) {
			return 0;
		}
		if (n % 2 == 0) {
			return integerReplacement(n / 2) + 1;
		}
		else {
			return min(integerReplacement(n / 2), integerReplacement(n / 2 + 1)) + 2;
		}
	}
};

int main() {
	system("pause");
	return 0;
}