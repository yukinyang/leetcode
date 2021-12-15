#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�

ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ ����������װ�õ������ ��һҹ֮���ܹ�͵�Ե�����߽�
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		if (nums.size() == 2) {
			return max(nums[0], nums[1]);
		}
		if (nums.size() == 3) {
			return max(nums[0] + nums[2], nums[1]);
		}
		int fir = nums[0], sec = nums[1], thr = nums[0] + nums[2];
		int ans = thr;
		for (int i = 3; i < nums.size(); ++i) {
			int now = max(nums[i] + sec, nums[i] + fir);
			ans = max(ans, now);
			fir = sec;
			sec = thr;
			thr = now;
		}
		return ans;
	}
};