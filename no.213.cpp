#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。

这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。

同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		int ans1 = 0, ans2 = 0;
		int pre1 = 0, pre2 = 0;
		int cur1 = 0, cur2 = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			ans1 = max(pre1 + nums[i], cur1);
			pre1 = cur1;
			cur1 = ans1;
			ans2 = max(pre2 + nums[i + 1], cur2);
			pre2 = cur2;
			cur2 = ans2;
		}
		return max(ans1, ans2);
	}
};