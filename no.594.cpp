#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
��г������ָһ��������Ԫ�ص����ֵ����Сֵ֮��Ĳ�� ������ 1 ��

���ڣ�����һ���������� nums �����������п��ܵ����������ҵ���ĺ�г�����еĳ��ȡ�

�������������һ���������������������У�������ͨ��ɾ��һЩԪ�ػ�ɾ��Ԫ�ء��Ҳ��ı�����Ԫ�ص�˳����õ���
*/

class Solution {
public:
	int findLHS(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		int begin = 0;
		int res = 0;
		for (int end = 0; end < nums.size(); end++) {
			while (nums[end] - nums[begin] > 1) {
				begin++;
			}
			if (nums[end] - nums[begin] == 1) {
				res = max(res, end - begin + 1);
			}
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}