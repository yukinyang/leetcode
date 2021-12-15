#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个下标从 0 开始的整数数组 nums 以及一个目标元素 target 。

目标下标 是一个满足 nums[i] == target 的下标 i 。

将 nums 按 非递减 顺序排序后，返回由 nums 中目标下标组成的列表。如果不存在目标下标，返回一个 空 列表。返回的列表必须按 递增 顺序排列。
*/

class Solution {
public:
	vector<int> targetIndices(vector<int>& nums, int target) {
		vector<int> res;
		sort(nums.begin(), nums.end());
		int l = 0;
		while (l < nums.size() && nums[l] <= target) {
			if (nums[l] == target) {
				res.push_back(l);
			}
			++l;
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> t = { 1 };
	vector<int> res = s.targetIndices(t, 1);
	system("pause");
	return 0;
}