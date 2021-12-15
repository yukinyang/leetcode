#include <iostream>
#include <vector>

using namespace std;

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。
*/

class Solution {
public:
	int climbStairs(int n) {
		/* dp */
		//vector<int> dp(n + 1, 1);
		//for (int i = 2; i <= n; ++i) {
		//	dp[i] = dp[i - 2] + dp[i - 1];
		//}
		//return dp[n];

		/* dp 节省空间 */
		int ans = 1;
		int fir = 0, sec = 1;
		for (int i = 1; i <= n; ++i) {
			ans = fir + sec;
			fir = sec;
			sec = ans;
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}