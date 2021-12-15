#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�

����ط����еķ��ݶ� Χ��һȦ ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�

ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ����� ��

����һ������ÿ�����ݴ�Ž��ķǸ��������飬������ �ڲ���������װ�õ������ �������ܹ�͵�Ե�����߽�
*/

class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 1) {
			return nums[0];
		}
		int ans1 = 0, ans2 = 0;
		int pre1 = 0, pre2 = 0;
		int cur1 = 0, cur2 = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			ans1 = max(pre1 + nums[i], cur1);
			pre1 = cur1;
			cur1 = ans1;
			ans2 = max(pre2 + nums[i + 1], cur2);
			pre2 = cur2;
			cur2 = ans2;
		}
		return max(ans1, ans2);
	}
};