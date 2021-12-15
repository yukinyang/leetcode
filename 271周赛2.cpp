#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
给你一个整数数组 nums 。nums 中，子数组的 范围 是子数组中最大元素和最小元素的差值。

返回 nums 中 所有 子数组范围的 和 。

子数组是数组中一个连续 非空 的元素序列。
*/

class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		long long ans = 0;
		int n = nums.size();
		int maxn, minn;
		for (int i = 0; i < n; ++i) {
			maxn = nums[i];
			minn = nums[i];
			for (int j = i; j < n; ++j) {
				maxn = max(maxn, nums[j]);
				minn = min(minn, nums[j]);
				ans += (maxn - minn);
			}
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}