#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		/* dp */
		//if (prices.size() == 1) {
		//	return 0;
		//}
		//int ans = 0, mid;
		//vector<int> day_profit;
		//for (int i = 1; i < prices.size(); ++i) {
		//	day_profit.push_back(prices[i] - prices[i - 1]);
		//}
		//mid = day_profit[0];
		//ans = max(ans, mid);
		//for (int i = 1; i < day_profit.size(); ++i) {
		//	mid = max(mid + day_profit[i], day_profit[i]);
		//	ans = max(ans, mid);
		//}
		//return ans;

		/* stack */
		//int ans = 0;
		//prices.push_back(0);
		//stack<int> pro;
		//pro.push(prices[0]);
		//int low = prices[0];
		//for (int i = 1; i < prices.size(); ++i) {
		//	while (pro.size() && prices[i] < pro.top()) {
		//		ans = max(pro.top() - low, ans);
		//		pro.pop();
		//	}
		//	if (pro.size() == 0) {
		//		low = prices[i];
		//	}
		//	pro.push(prices[i]);
		//}
		//return ans;

		/* 一次遍历 */
		int ans = 0, low = prices[0];
		for (int i = 0; i < prices.size(); ++i) {
			ans = max(ans, prices[i] - low);
			low = min(low, prices[i]);
		}
		return ans;
	}
};