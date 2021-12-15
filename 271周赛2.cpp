#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
����һ���������� nums ��nums �У�������� ��Χ �������������Ԫ�غ���СԪ�صĲ�ֵ��

���� nums �� ���� �����鷶Χ�� �� ��

��������������һ������ �ǿ� ��Ԫ�����С�
*/

class Solution {
public:
	long long subArrayRanges(vector<int>& nums) {
		long long ans = 0;
		int n = nums.size();
		int maxn, minn;
		for (int i = 0; i < n; ++i) {
			maxn = nums[i];
			minn = nums[i];
			for (int j = i; j < n; ++j) {
				maxn = max(maxn, nums[j]);
				minn = min(minn, nums[j]);
				ans += (maxn - minn);
			}
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}