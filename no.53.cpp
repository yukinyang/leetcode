#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		int ans = dp[0];
		for (int i = 1; i < nums.size(); ++i) {
			dp[i] = max(nums[i], nums[i] + dp[i - 1]);
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}