#include <iostream>
#include <vector>

using namespace std;

/*
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

请必须使用时间复杂度为 O(log n) 的算法。
*/

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		if (nums.size() == 1) {
			return target > nums[0] ? 1 : 0;
		}
		if (target > nums[nums.size() - 1]) {
			return nums.size();
		}
		if (target < nums[0]) {
			return 0;
		}
		while (l <= r) {
			int mid = (l + r) / 2;
			// cout << mid << endl;
			if (nums[mid] == target) {
				// cout << 999 << endl;
				return mid;
			}
			else if (nums[mid] > target) {
				r = mid - 1;
			}
			else {
				l = mid + 1;
			}
		}
		return nums[l] > target ? l : l + 1;
	}
};

int main() {
	system("pause");
	return 0;
}