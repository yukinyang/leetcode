#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

/*
给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
*/

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> dq;
		int lhs = 0, rhs = 0;
		vector<int> res;
		while (rhs < nums.size()) {
			while (dq.size() && nums[rhs] >= nums[dq.back()]) 
				dq.pop_back();
			dq.push_back(rhs);
			if (rhs >= k) {
				lhs++;
				if (lhs > dq.front()) dq.pop_front();
			}
			if (rhs >= k - 1)
				res.push_back(nums[dq.front()]);
			rhs++;
		}
		return res;
	}
};

int main() {
	vector<int> input = { 1,3,-1,-3,5,3,6,7 };
	Solution s;
	vector<int> res = s.maxSlidingWindow(input, 3);
	for (int num : res) {
		cout << num << endl;
	}
	system("pause");
	return 0;
}