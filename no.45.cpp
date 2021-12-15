#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

假设你总是可以到达数组的最后一个位置。
*/

class Solution {
public:
	int jump(vector<int>& nums) {
		int start = 0, end = 0, maxstep = 0;
		int ans = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			maxstep = max(maxstep, i + nums[i]);
			if (i == end) {
				++ans;
				end = maxstep;
			}
		}
		return ans;
	}
};