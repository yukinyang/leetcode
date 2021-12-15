#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
给你一个下标从 0 开始的数组 nums ，数组中有 n 个整数，另给你一个整数 k 。

半径为 k 的子数组平均值 是指：nums 中一个以下标 i 为 中心 且 半径 为 k 的子数组中所有元素的平均值，即下标在 i - k 和 i + k 范围（含 i - k 和 i + k）内所有元素的平均值。

如果在下标 i 前或后不足 k 个元素，那么 半径为 k 的子数组平均值 是 -1 。

构建并返回一个长度为 n 的数组 avgs ，其中 avgs[i] 是以下标 i 为中心的子数组的 半径为 k 的子数组平均值 。

x 个元素的 平均值 是 x 个元素相加之和除以 x ，此时使用截断式 整数除法 ，即需要去掉结果的小数部分。

例如，四个元素 2、3、1 和 5 的平均值是 (2 + 3 + 1 + 5) / 4 = 11 / 4 = 3.75，截断后得到 3 。
*/

class Solution {
public:
	vector<int> getAverages(vector<int>& nums, int k) {
		vector<int> res(nums.size(), -1);
		queue<int> mid;
		double all = 0;
		if (nums.size() < 2 * k + 1) {
			return res;
		}
		for (int i = 0; i < 2 * k + 1; ++i) {
			mid.push(nums[i]);
			all += nums[i];
		}
		res[k] = int(all / (2 * k + 1));
		for (int i = k + 1; i < nums.size() - k; ++i) {
			int fr = mid.front();
			all = all - fr + nums[i + k];
			mid.pop();
			mid.push(nums[i + k]);
			res[i] = int(all / (2 * k + 1));
		}
		return res;
	}
};

int main() {
	Solution s;
	system("pause");
	return 0;
}