#include <iostream>
#include <string>

using namespace std;

/*
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
*/

class Solution {
public:
	string replaceSpace(string s) {
		string ans;
		for (char ch : s) {
			if (ch == ' ') {
				ans += "%20";
			}
			else {
				ans.push_back(ch);
			}
		}
		return ans;
	}
};