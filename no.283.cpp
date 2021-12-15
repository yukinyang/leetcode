#include <iostream>
#include <vector>

using namespace std;

/*
����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
*/

class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		/* ���� */
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
		
		/* ˫ָ�� */
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

		/* ˫ָ��Ľ� */
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