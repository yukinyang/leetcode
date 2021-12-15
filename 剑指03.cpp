#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	�ҳ��������ظ������֡�

	��һ������Ϊ n ������ nums ����������ֶ��� 0��n-1 �ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡�
*/

class Solution {
public:
	int findRepeatNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int n = nums.size(), res = 0, last;
		last = nums[0];
		for (int i = 1; i < n; i++) {
			if (nums[i] == last) {
				res = nums[i];
				break;
			}
			last = nums[i];
		}
		return res;
	}
};

int main() {
	return 0;
}