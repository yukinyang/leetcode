#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
����һ���������� nums ��һ������ k ������Ҫ�ҵ� nums �г���Ϊ k �� ������ ������������е� ����� ��

���㷵�� ���� һ������Ϊ k �����������С�

������ ����Ϊ��һ��������ɾ��һЩԪ�غ󣬲��ı�ʣ��Ԫ�ص�˳��õ������顣
*/

bool paixu(vector<int>& a, vector<int>& b) {
	return a[0] > b[0];
}

class Solution {
public:
	vector<int> maxSubsequence(vector<int>& nums, int k) {
		vector<vector<int>> newnums;
		vector<int> bits;
		vector<int> ans;
		int n = nums.size();
		for (int i = 0; i < n; ++i) {
			newnums.push_back({ nums[i], i });
		}
		sort(newnums.begin(), newnums.end(), paixu);
		for (int i = 0; i < k; ++i) {
			bits.push_back(newnums[i][1]);
		}
		sort(bits.begin(), bits.end());
		for (auto bit : bits) {
			ans.push_back(nums[bit]);
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}