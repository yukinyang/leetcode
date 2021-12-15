#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ���±�� 0 ��ʼ���������� nums �Լ�һ��Ŀ��Ԫ�� target ��

Ŀ���±� ��һ������ nums[i] == target ���±� i ��

�� nums �� �ǵݼ� ˳������󣬷����� nums ��Ŀ���±���ɵ��б����������Ŀ���±꣬����һ�� �� �б����ص��б���밴 ���� ˳�����С�
*/

class Solution {
public:
	vector<int> targetIndices(vector<int>& nums, int target) {
		vector<int> res;
		sort(nums.begin(), nums.end());
		int l = 0;
		while (l < nums.size() && nums[l] <= target) {
			if (nums[l] == target) {
				res.push_back(l);
			}
			++l;
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> t = { 1 };
	vector<int> res = s.targetIndices(t, 1);
	system("pause");
	return 0;
}