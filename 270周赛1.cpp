#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

*/

class Solution {
public:
	vector<int> ans;
	vector<int> nums_used;
	vector<int> findEvenNumbers(vector<int>& digits) {
		nums_used.resize(1000, 0);
		sort(digits.begin(), digits.end());
		vector<int> used(digits.size(), 0);
		dfs(digits, used, 0, 0);
		sort(ans.begin(), ans.end());
		return ans;
	}

	void dfs(vector<int>& digits, vector<int>& used, int num, int bit) {
		if (num < 1000 && num > 99 && num % 2 == 0 && nums_used[num] == 0) {
			if (ans.size() > 0 && ans[ans.size() - 1] == num) {
				return;
			}
			ans.push_back(num);
			nums_used[num] = 1;
			return;
		}
		for (int i = 0; i < digits.size(); ++i) {
			if (used[i] == 1 || (bit == 0 && digits[i] == 0)) {
				continue;
			}
			used[i] = 1;
			num *= 10;
			num += digits[i];
			dfs(digits, used, num, bit + 1);
			num -= digits[i];
			num /= 10;
			used[i] = 0;
		}
	}
};

int main() {
	vector<int> input = { 5, 7, 2, 4, 8, 2, 6, 6, 0, 9 };
	Solution s;
	vector<int> ans = s.findEvenNumbers(input);
	for (int a : ans) {
		cout << a << endl;
	}
	system("pause");
	return 0;
}