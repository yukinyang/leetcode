#include <iostream>
#include <vector>

using namespace std;

/*
给你一个数组，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		/* 暴力，超时 */
		//for (int i = 0; i < k; ++i) {
		//	int mid = nums[nums.size() - 1];
		//	nums.pop_back();
		//	nums.insert(nums.begin(), mid);
		//}
		vector<int> front(nums.begin(), nums.begin() + nums.size() - k);
		vector<int> back(nums.begin() + nums.size() - k, nums.end());
		back.insert(back.end(), front.begin(), front.end());
		nums = back;
	}
};