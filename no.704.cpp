﻿#include <iostream>
#include <vector>

using namespace std;

/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
*/

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0; 
		int r = nums.size() - 1;
		while (l <= r) {
			int mid = (r - l) / 2 + l;
			if (nums[mid] == target) {
				return mid;
			}
			if (nums[mid] > target) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return -1;
	}
};

