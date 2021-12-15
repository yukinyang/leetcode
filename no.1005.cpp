#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。
*/

class Solution {
public:
	int largestSumAfterKNegations(vector<int>& nums, int k) {
		int sum = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); ++i) {
			sum += nums[i];
		}
		if (nums[0] >= 0) {
			return k % 2 == 0 ? sum : sum - 2 * nums[0];
		}
		int i = 0;
		while ((i < nums.size() && nums[i] < 0) && k > 0) {
			sum -= 2 * nums[i];
			nums[i] *= -1;
			--k;
			++i;
		}
		if (k == 0) {
			return sum;
		}
		else {
			sort(nums.begin(), nums.end());
			return k % 2 == 0 ? sum : sum - 2 * nums[0];
		}
	}
};

int main() {
	system("pause");
	return 0;
}