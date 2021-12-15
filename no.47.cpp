#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
*/

class Solution {
public:
	vector<int> visit;

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> mid;
		visit.resize(nums.size());
		sort(nums.begin(), nums.end());
		get_res(nums, res, 0, mid);
		return res;
	}

	void get_res(vector<int> nums, vector<vector<int>>& res, int index, vector<int>& mid) {
		if (index == nums.size()) {
			res.push_back(mid);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (visit[i] || (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1])) {
				continue;
			}
			mid.push_back(nums[i]);
			visit[i] = 1;
			get_res(nums, res, index + 1, mid);
			mid.pop_back();
			visit[i] = 0;
		}
	}
};

int main() {
	int a[3] = { 1, 1, 2 };
	Solution s;
	vector<int> input(a, a + 3);
	vector<vector<int>> res = s.permuteUnique(input);
	cout << res.size();
	system("pause");
	return 0;
}