#include <iostream>
#include <vector>

using namespace std;

/*
����һ���������� nums ������㷨������һ��û���ظ�Ԫ�ص����顣

ʵ�� Solution class:

Solution(int[] nums) ʹ���������� nums ��ʼ������
int[] reset() �������鵽���ĳ�ʼ״̬������
int[] shuffle() ��������������Һ�Ľ��
*/

class Solution {
public:
	vector<int> re;
	vector<int> used;
	Solution(vector<int>& nums) {
		re = nums;
		used.resize(nums.size(), 0);
	}

	vector<int> reset() {
		return re;
	}

	vector<int> shuffle() {
		vector<int> res;
		int now;
		for (int i = 0; i < re.size(); ++i) {
			now = rand() % re.size();
			while (used[now] == 1) {
				now = rand() % re.size();
			}
			used[now] = 1;
			res.push_back(re[now]);
		}
		fill(used.begin(), used.end(), 0);
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}