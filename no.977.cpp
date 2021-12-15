#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
*/

class Solution {
public:
	vector<int> sortedSquares(vector<int>& nums) {
		int l = 0, r = nums.size() - 1;
		vector<int> ans(nums.size(), 0);
		for (int i = nums.size() - 1; i >= 0; --i) {
			if (abs(nums[l]) < abs(nums[r])) {
				ans[i] = nums[r] * nums[r];
				--r;
			}
			else {
				ans[i] = nums[l] * nums[l];
				++l;
			}
		}
		return ans;
	}
};