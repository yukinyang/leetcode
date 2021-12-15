#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。

换句话说，s1 的排列之一是 s2 的 子串 。
*/

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int> letter1(26, 0), letter2(26, 0);
		queue<char> let2;
		int n = s1.size(), n2 = s2.size();
		if (n > n2) {
			return false;
		}
		for (char ch : s1) {
			++letter1[ch - 'a'];
		}
		for (int i = 0; i < n; ++i) {
			++letter2[s2[i] - 'a'];
			let2.push(s2[i]);
		}
		if (letter1 == letter2) {
			return true;
		}
		for (int i = n; i < n2; ++i) {
			let2.push(s2[i]);
			char mid = let2.front();
			let2.pop();
			++letter2[s2[i] - 'a'];
			--letter2[mid - 'a'];
			if (letter1 == letter2) {
				return true;
			}
		}
		return false;
	}
};