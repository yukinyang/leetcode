#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
我们正在玩一个猜数游戏，游戏规则如下：

我从 1 到 n 之间选择一个数字。
你来猜我选了哪个数字。
如果你猜到正确的数字，就会 赢得游戏 。
如果你猜错了，那么我会告诉你，我选的数字比你的 更大或者更小 ，并且你需要继续猜数。
每当你猜了数字 x 并且猜错了的时候，你需要支付金额为 x 的现金。如果你花光了钱，就会 输掉游戏 。
给你一个特定的数字 n ，返回能够 确保你获胜 的最小现金数，不管我选择那个数字 。
*/

class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		if (n < 2) {
			return 0;
		}
		dp[1][2] = 1;
		for (int i = 3; i < n + 1; ++i) {
			for (int j = i - 1; j > 0; --j) {
				dp[j][i] = INT_MAX;
				for (int k = j; k < i; ++k) {
					dp[j][i] = min(dp[j][i], k + max(dp[j][k - 1], dp[k + 1][i]));
				}
			}
		}
		return dp[1][n];
	}
};

int main() {
	Solution s;
	int res = s.getMoneyAmount(200);
	cout << res << endl;
	system("pause");
	return 0;
}