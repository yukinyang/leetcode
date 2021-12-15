#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，找出三个长度为 k 、互不重叠、且 3 * k 项的和最大的子数组，并返回这三个子数组。

以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置（下标从 0 开始）。如果有多个结果，返回字典序最小的一个。
*/

struct sum_bit{
	double s;
	int b;
	sum_bit(double x, int y) {
		s = x;
		b = y;
	}
};

bool cmp_sum_bit(sum_bit x, sum_bit y) {
	if (x.s > y.s) {
		return true;
	}
	if (x.s == y.s) {
		return x.b < y.b;
	}
	return false;
}

class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		vector<int> ans(3, 0);
		vector<sum_bit> Sumk;
		double mid_sum = 0;
		for (int i = 0; i < k; ++i) {
			mid_sum += nums[i];
		}
		Sumk.push_back(sum_bit(mid_sum, 0));
		for (int i = k; i < nums.size(); ++i) {
			mid_sum -= nums[i - k];
			mid_sum += nums[i];
			cout << mid_sum << ' ';
			Sumk.push_back(sum_bit(mid_sum, i - k + 1));
		}
		cout << endl;
		sort(Sumk.begin(), Sumk.end(), cmp_sum_bit);
		for (auto a : Sumk) {
			cout << a.s << ' ' << a.b << endl;
		}
		ans[0] = Sumk[0].b;
		ans[1] = Sumk[1].b;
		ans[2] = Sumk[2].b;
		return ans;
	}
};

class Solution {
public:
	vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
		// 记录3个滑动窗口的值
		int sum1 = 0, sum2 = 0, sum3 = 0;
		// 记录最大值
		int maxSum0 = 0, maxSum1 = 0, maxSum12 = 0, maxSum = 0;
		// 记录最大值所对应窗口的下标
		int idx[4];
		vector<int> ans;
		for (int i = 2 * k; i < nums.size(); i++) {
			// 每次i移动一个位置，然后改变3个滑动窗口的值
			sum1 += nums[i - 2 * k];
			sum2 += nums[i - k];
			sum3 += nums[i];
			// 如果三个窗口的值，都可以取到，则开始维护最大值
			if (i >= 3 * k - 1) {
				// 如果第一个窗口当前值，大于第一个窗口之前维护的最大值，则更新最大值并记录窗口下标
				if (sum1 > maxSum1) {
					idx[0] = i - 3 * k + 1;
					maxSum1 = sum1;
				}
				// 如果第二个窗口当前值 + 第一个窗口最大值 大于之前维护的最大值，则更新最大值并记录窗口下标
				if (sum2 + maxSum1 > maxSum12) {
					idx[1] = idx[0];
					idx[2] = i - 2 * k + 1;
					maxSum12 = sum2 + maxSum1;
				}
				// 如果第三个窗口当前值 + 前两个窗口最大值 大于之前维护的最大值，则更新最大值并记录窗口下标
				if (maxSum12 + sum3 > maxSum) {
					idx[3] = i - k + 1;
					maxSum = maxSum12 + sum3;
					ans = { idx[1], idx[2], idx[3] };
				}
				// 每次i移动一个位置，然后改变3个滑动窗口的值
				sum1 -= nums[i - 3 * k + 1];
				sum2 -= nums[i - 2 * k + 1];
				sum3 -= nums[i - k + 1];
			}
		}
		return ans;
	}
};

int main() {
	vector<int> nums = { 1,2,1,2,6,7,5,1 };
	int k = 2;
	Solution s;
	vector<int> ans = s.maxSumOfThreeSubarrays(nums, k);
	system("pause");
	return 0;
}