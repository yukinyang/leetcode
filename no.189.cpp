#include <iostream>
#include <vector>

using namespace std;

/*
����һ�����飬�������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ�����
*/

class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		k = k % nums.size();
		/* ��������ʱ */
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