#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
����һ���±�� 0 ��ʼ������ nums ���������� n �������������һ������ k ��

�뾶Ϊ k ��������ƽ��ֵ ��ָ��nums ��һ�����±� i Ϊ ���� �� �뾶 Ϊ k ��������������Ԫ�ص�ƽ��ֵ�����±��� i - k �� i + k ��Χ���� i - k �� i + k��������Ԫ�ص�ƽ��ֵ��

������±� i ǰ����� k ��Ԫ�أ���ô �뾶Ϊ k ��������ƽ��ֵ �� -1 ��

����������һ������Ϊ n ������ avgs ������ avgs[i] �����±� i Ϊ���ĵ�������� �뾶Ϊ k ��������ƽ��ֵ ��

x ��Ԫ�ص� ƽ��ֵ �� x ��Ԫ�����֮�ͳ��� x ����ʱʹ�ýض�ʽ �������� ������Ҫȥ�������С�����֡�

���磬�ĸ�Ԫ�� 2��3��1 �� 5 ��ƽ��ֵ�� (2 + 3 + 1 + 5) / 4 = 11 / 4 = 3.75���ضϺ�õ� 3 ��
*/

class Solution {
public:
	vector<int> getAverages(vector<int>& nums, int k) {
		vector<int> res(nums.size(), -1);
		queue<int> mid;
		double all = 0;
		if (nums.size() < 2 * k + 1) {
			return res;
		}
		for (int i = 0; i < 2 * k + 1; ++i) {
			mid.push(nums[i]);
			all += nums[i];
		}
		res[k] = int(all / (2 * k + 1));
		for (int i = k + 1; i < nums.size() - k; ++i) {
			int fr = mid.front();
			all = all - fr + nums[i + k];
			mid.pop();
			mid.push(nums[i + k]);
			res[i] = int(all / (2 * k + 1));
		}
		return res;
	}
};

int main() {
	Solution s;
	system("pause");
	return 0;
}