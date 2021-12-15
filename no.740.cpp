﻿#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。
*/

class Solution {
public:
	int deleteAndEarn(vector<int>& nums) {
		vector<int> num;
		unordered_map<int, int> map;
		for (int i : nums) {
			if (map.find(i) == map.end()) {
				map[i] = i;
				num.push_back(i);
			}
			else {
				map[i] += i;
			}
		}
		sort(num.begin(), num.end());
		int pre = 0, ans = 0;
		for (int i = 0; i < num.size(); ++i) {
			if (map.find(nums[i - 1]) == map.end()) {
				pre = ans;
				ans += map[nums[i]];
			}
			else {
				int mid = max(map[nums[i]] + pre, ans);
				pre = ans;
				ans = mid;
			}
		}
		return ans;
	}
};