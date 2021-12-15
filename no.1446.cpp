#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。

请你返回字符串的能量。
*/

class Solution {
public:
	int maxPower(string s) {
		int ans = 1;
		int mid = 1;
		bool get = false;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] != s[i - 1]) {
				ans = max(ans, mid);
				mid = 1;
				get = false;
			}
			if (get == false && s[i] == s[i - 1]) {
				get = true;
				mid = 2;
				continue;
			}
			if (get && s[i] == s[i - 1]) {
				++mid;
			}
		}
		ans = max(ans, mid);
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}