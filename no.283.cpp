#include <iostream>
#include <vector>

using namespace std;

/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		/* 暴力 */
		//vector<int> zeros;
		//for (int i = 0; i < nums.size(); ++i) {
		//	if (nums[i] == 0) {
		//		zeros.push_back(i);
		//	}
		//}
		//int n = zeros.size();
		//for (int i = 0; i < n; ++i) {
		//	int now = zeros[zeros.size() - 1];
		//	for (int j = now; j < nums.size() - i - 1; ++j) {
		//		nums[j] = nums[j + 1];
		//		nums[j + 1] = 0;
		//	}
		//	zeros.pop_back();
		//}
		
		/* 双指针 */
		//int l = 0, r = 0;
		//while (r < nums.size()) {
		//	if (nums[r] != 0) {
		//		nums[l] = nums[r];
		//		++l;
		//	}
		//	++r;
		//}
		//for (int i = l; i < nums.size(); ++i) {
		//	nums[l] = 0;
		//}

		/* 双指针改进 */
		int l = 0, r = 0;
		while (r < nums.size()) {
			if (nums[r] != 0) {
				swap(nums[l], nums[r]);
				++l;
			}
			++r;
		}
	}
};