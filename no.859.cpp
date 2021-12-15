#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
给你两个字符串 s 和 goal ，只要我们可以通过交换 s 中的两个字母得到与 goal 相等的结果，就返回 true ；否则返回 false 。

交换字母的定义是：取两个下标 i 和 j （下标从 0 开始）且满足 i != j ，接着交换 s[i] 和 s[j] 处的字符。

例如，在 "abcd" 中交换下标 0 和下标 2 的元素可以生成 "cbad" 。
*/

class Solution {
public:
	bool buddyStrings(string s, string goal) {
		int dif = 0;
		char s1, s2, g1, g2;
		if (s.size() != goal.size() || s.size() < 2) {
			return false;
		}
		if (s == goal) {
			sort(s.begin(), s.end());
			for (int i = 1; i < s.size(); ++i) {
				if (s[i] == s[i - 1]) {
					return true;
				}
			}
		}
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != goal[i]) {
				++dif;
				if (dif == 1) {
					s1 = s[i];
					g1 = goal[i];
				}
				else if (dif == 2) {
					s2 = s[i];
					g2 = goal[i];
				}
				else {
					return false;
				}
			}
		}
		return s1 == g2 && s2 == g1;
	}
};

int main() {
	system("pause");
	return 0;
}