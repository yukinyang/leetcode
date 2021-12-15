#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个由整数数组 A 表示的环形数组 C，求 C 的非空子数组的最大可能和。

在此处，环形数组意味着数组的末端将会与开头相连呈环状。（形式上，当0 <= i < A.length 时 C[i] = A[i]，且当 i >= 0 时 C[i+A.length] = C[i]）

此外，子数组最多只能包含固定缓冲区 A 中的每个元素一次。（形式上，对于子数组 C[i], C[i+1], ..., C[j]，不存在 i <= k1, k2 <= j 其中 k1 % A.length = k2 % A.length）
*/

class Solution {
public:
	int maxSubarraySumCircular(vector<int>& nums) {
		int n = nums.size(), ans = 0;
		if (n == 0) {
			return nums[0];
		}
		int ma = nums[0], mi = nums[0], sum = 0;
		int all_ma = nums[0], all_mi = nums[0];
		sum += nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			sum += nums[i];
			ma = max(ma + nums[i], nums[i]);
			mi = min(mi + nums[i], nums[i]);
			all_ma = max(all_ma, ma);
			all_mi = min(all_mi, mi);
		}
		if (all_ma <= 0) {
			return all_ma;
		}
		return max(all_ma, sum - all_mi);
	}
};