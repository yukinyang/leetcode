#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。
*/

class Solution {
public:
	/* dfs */
	//vector<vector<int>> ans;
	//vector<vector<int>> fourSum(vector<int>& nums, int target) {
	//	if (nums.size() < 4) {
	//		return ans;
	//	}
	//	vector<int> mid;
	//	sort(nums.begin(), nums.end());
	//	dfs(nums, mid, target, 0, 0);
	//	return ans;
	//}

	//void dfs(vector<int>& nums, vector<int>& mid, int target, long sum, int now) {
	//	if (mid.size() == 4 && sum == target) {
	//		ans.push_back(mid);
	//		return;
	//	}
	//	for (int i = now; i < nums.size(); ++i) {
	//		if (nums.size() - now < 4 - mid.size()) {
	//			return;
	//		}
	//		if (i > now && nums[i] == nums[i - 1]) {
	//			continue;
	//		}
	//		if (i < nums.size() - 1 && sum + nums[i] + long(3 - mid.size()) * nums[i + 1] > target) {
	//			return;
	//		}
	//		if (i < nums.size() - 1 && sum + nums[i] + long(3 - mid.size()) * nums[nums.size() - 1] < target) {
	//			continue;
	//		}
	//		sum += nums[i];
	//		mid.push_back(nums[i]);
	//		dfs(nums, mid, target, sum, i + 1);
	//		mid.pop_back();
	//		sum -= nums[i];
	//	}
	//	return;
	//}

	/* 双（四）指针 */
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> ans;
		sort(nums.begin(), nums.end());
		long sum;
		for (int a = 0; a < int(nums.size()) - 3; ++a) {
			if (a > 0 && nums[a] == nums[a - 1]) {
				continue;
			}
			for (int b = a + 1; b < nums.size() - 2; ++b) {
				if (b > a + 1 && nums[b] == nums[b - 1]) {
					continue;
				}
				int c = b + 1;
				int d = nums.size() - 1;
				while (c < d) {
					if (c > b + 1 && nums[c] == nums[c - 1]) {
						++c;
						continue;
					}
					if (d < nums.size() - 1 && nums[d] == nums[d + 1]) {
						--d;
						continue;
					}
					sum = long(nums[a]) + long(nums[b]) + long(nums[c]) + long(nums[d]);
					if (sum == target) {
						ans.push_back({ nums[a], nums[b], nums[c], nums[d] });
						++c;
						--d;
					}
					else if (sum < target) {
						++c;
					}
					else {
						--d;
					}
				}
			}
		}
		return ans;
	}
};