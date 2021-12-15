#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 nums ，请你求出乘积为正数的最长子数组的长度。

一个数组的子数组是由原数组中零个或者更多个连续数字组成的数组。

请你返回乘积为正数的最长子数组长度。
*/

class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int ans, max_zheng = 0, max_fu = 0, last_zheng = 0, last_fu = 0;
		int n = nums.size();
		if (nums[0] < 0) {
			last_fu = 1;
		}
		else if (nums[0] > 0) {
			last_zheng = 1;
		}
		ans = last_zheng;
		for (int i = 1; i < n; ++i) {
			if (nums[i] == 0) {
				max_zheng = 0;
				max_fu = 0;
			}
			else {
				if (nums[i] < 0) {
					max_zheng = (last_fu > 0 ? last_fu + 1 : 0);
					max_fu = last_zheng + 1;
				}
				else {
					max_zheng = last_zheng + 1;
					max_fu = (last_fu > 0 ? last_fu + 1 : 0);
				}
			}
			ans = max(ans, max_zheng);
			// cout << max_zheng << ' ' << ans << endl;
			last_zheng = max_zheng;
			last_fu = max_fu;
		}
		return ans;
	}
};