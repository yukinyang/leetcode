#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个下标从 0 开始的数组 nums ，数组由若干 互不相同 的整数组成。

nums 中有一个值最小的元素和一个值最大的元素。分别称为 最小值 和 最大值 。你的目标是从数组中移除这两个元素。

一次 删除 操作定义为从数组的 前面 移除一个元素或从数组的 后面 移除一个元素。

返回将数组中最小值和最大值 都 移除需要的最小删除次数。
*/

class Solution {
public:
	int minimumDeletions(vector<int>& nums) {
		vector<int> mid = nums;
		sort(mid.begin(), mid.end());
		int xiao, da;
		bool getx = false, getd = false;
		for (int i = 0; i < nums.size(); ++i) {
			if (mid[0] == nums[i]) {
				xiao = i;
				getx = true;
			}
			if (mid[nums.size() - 1] == nums[i]) {
				da = i;
				getd = true;
			}
			if (getd && getx) {
				break;
			}
		}
		int a, b, c;
		a = max(xiao, da) +1;
		b = nums.size() - min(xiao, da) + 1;
		c = nums.size() - max(xiao, da) + 1 + min(xiao, da) + 1;
		return min(a, min(b, c));
	}
};

int main() {
	system("pause");
	return 0;
}