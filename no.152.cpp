#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ���������� nums �������ҳ������г˻��������������飨�������������ٰ���һ�����֣��������ظ�����������Ӧ�ĳ˻���
*/

class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int ans = nums[0], mid_max = nums[0], mid_min = nums[0];
		int n = nums.size();
		for (int i = 1; i < n; ++i) {
			int now_max = mid_max, now_min = mid_min;
			mid_max = max(max(nums[i], nums[i] * now_max), nums[i] * now_min);
			mid_min = min(min(nums[i], nums[i] * now_min), nums[i] * now_max);
			ans = max(mid_max, ans);
		}
		return ans;
	}
};