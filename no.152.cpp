#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int ans = nums[0], mid_max = nums[0], mid_min = nums[0];
		int n = nums.size();
		for (int i = 1; i < n; ++i) {
			int now_max = mid_max, now_min = mid_min;
			mid_max = max(max(nums[i], nums[i] * now_max), nums[i] * now_min);
			mid_min = min(min(nums[i], nums[i] * now_min), nums[i] * now_max);
			ans = max(mid_max, ans);
		}
		return ans;
	}
};