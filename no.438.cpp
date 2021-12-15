#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。
*/

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		/* 暴力，超时 */
		//vector<int> res;
		//if (s.size() < p.size()) {
		//	return res;
		//}
		//string std = p;
		//sort(std.begin(), std.end());
		//for (int i = 0; i <= s.size() - p.size(); ++i) {
		//	string mid(s, i, p.size());
		//	sort(mid.begin(), mid.end());
		//	if (mid == std) {
		//		res.push_back(i);
		//	}
		//}
		/* 滑动窗口 */
		vector<int> res;
		if (s.size() < p.size()) {
			return res;
		}
		vector<int> p_nums(26, 0);
		vector<int> mid_nums(26, 0);
		for (char ch : p) {
			++p_nums[ch - 'a'];
		}
		for (int i = 0; i < p.size(); ++i) {
			++mid_nums[s[i] - 'a'];
		}
		if (mid_nums == p_nums) {
			res.push_back(0);
		}
		for (int i = p.size(); i < s.size(); ++i) {
			--mid_nums[s[i - p.size()] - 'a'];
			++mid_nums[s[i] - 'a'];
			if (mid_nums == p_nums) {
				res.push_back(i - p.size() + 1);
			}
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}