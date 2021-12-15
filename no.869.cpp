#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定正整数 N ，我们按任何顺序（包括原始顺序）将数字重新排序，注意其前导数字不能为零。

如果我们可以通过上述方式得到 2 的幂，返回 true；否则，返回 false。
*/

class Solution {
public:
	vector<int> visit;
	bool reorderedPowerOf2(int n) {
		vector<int> nums;
		vector<int> mid;
		while (n != 0) {
			nums.push_back(n % 10);
			n /= 10;
		}
		visit.resize(nums.size());
		sort(nums.begin(), nums.end());
		return get_res(nums, 0, mid);
	}

	bool is2mi(int n) {
		return n > 0 && ((n & (n - 1)) == 0);
	}

	bool get_res(vector<int> nums, int index, vector<int> mid) {
		if (index == nums.size()) {
			int num = 0;
			for (int i = 0; i < mid.size(); i++) {
				num *= 10;
				num += mid[i];
			}
			return is2mi(num);
		}
		for (int i = 0; i < nums.size(); i++) {
			if (index == 0 && nums[i] == 0) {
				continue;
			}
			if (i > 0 && nums[i] == nums[i - 1] && !visit[i - 1]) {
				continue;
			}
			if (visit[i]) {
				continue;
			}
			visit[i] = 1;
			mid.push_back(nums[i]);
			if (get_res(nums, index + 1, mid)) {
				return true;
			}
			visit[i] = 0;
			mid.pop_back();
		}
		return false;
	}
};

int main() {
	Solution s;
	bool res;
	res = s.reorderedPowerOf2(1042);
	cout << boolalpha << res << endl;
	system("pause");
	return 0;
}