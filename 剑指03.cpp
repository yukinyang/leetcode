#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	找出数组中重复的数字。

	在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
*/

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), res = 0, last;
		last = nums[0];
		for (int i = 1; i < n; i++) {
			if (nums[i] == last) {
				res = nums[i];
				break;
			}
			last = nums[i];
		}
		return res;
	}
};

int main() {
	return 0;
}