#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ���Ǹ��������� nums �������λ������� ��һ���±� ��

�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�

�ж����Ƿ��ܹ��������һ���±ꡣ
*/

class Solution {
public:
	bool canJump(vector<int>& nums) {
		int bit = -1, max_get = 0;
		for (int i = 0; i < nums.size() - 1; ++i) {
			bit = i;
			max_get = max(max_get, bit + nums[bit]);
			if (bit >= max_get) {
				return false;
			}
		}
		return true;
	}
};