#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。
*/

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int bit = -1, max_get = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			bit = i;
			max_get = max(max_get, bit + nums[bit]);
			if (bit >= max_get) {
				return false;
			}
		}
		return true;
	}
};