#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
你是一个专业的小偷，计划偷窃沿街的房屋。

每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}
		if (nums.size() == 3) {
			return max(nums[0] + nums[2], nums[1]);
		}
		int fir = nums[0], sec = nums[1], thr = nums[0] + nums[2];
		int ans = thr;
		for (int i = 3; i < nums.size(); ++i) {
			int now = max(nums[i] + sec, nums[i] + fir);
			ans = max(ans, now);
			fir = sec;
			sec = thr;
			thr = now;
		}
		return ans;
	}
};