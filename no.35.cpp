#include <iostream>
#include <vector>

using namespace std;

/*
����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨��
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