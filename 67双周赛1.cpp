#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
给你一个整数数组 nums 和一个整数 k 。你需要找到 nums 中长度为 k 的 子序列 ，且这个子序列的 和最大 。

请你返回 任意 一个长度为 k 的整数子序列。

子序列 定义为从一个数组里删除一些元素后，不改变剩下元素的顺序得到的数组。
*/

bool paixu(vector<int>& a, vector<int>& b) {
	return a[0] > b[0];
}

class Solution {
public:
	vector<int> maxSubsequence(vector<int>& nums, int k) {
		vector<vector<int>> newnums;
		vector<int> bits;
		vector<int> ans;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			newnums.push_back({ nums[i], i });
		}
		sort(newnums.begin(), newnums.end(), paixu);
		for (int i = 0; i < k; ++i) {
			bits.push_back(newnums[i][1]);
		}
		sort(bits.begin(), bits.end());
		for (auto bit : bits) {
			ans.push_back(nums[bit]);
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}