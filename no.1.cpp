#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		vector<int> ans(2, 0);
		unordered_map<int, int> map;
		for (int i = 0; i < nums.size(); ++i) {
			if (map.find(target - nums[i]) != map.end()) {
				ans[0] = map[target - nums[i]];
				ans[1] = i;
				return ans;
			}
			map[nums[i]] = i;
		}
		return ans;
	}
};