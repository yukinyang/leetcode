#include <iostream>
#include <vector>

using namespace std;

/*
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。
*/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		vector<int> last = { 1 };
		ans.push_back(last);
		vector<int> mid;
		for (int i = 1; i < numRows; ++i) {
			mid.resize(i + 1, 1);
			for (int j = 1; j < mid.size() - 1; ++j) {
				mid[j] = last[j - 1] + last[j + 1];
			}
			ans.push_back(mid);
			last = mid;
		}
		return ans;
	}
};