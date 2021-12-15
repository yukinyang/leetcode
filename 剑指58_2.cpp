#include <iostream>
#include <string>

using namespace std;

/*
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。

请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
*/

class Solution {
public:
	string reverseLeftWords(string s, int n) {
		int len = s.size();
		string ans(s, n, len - 1);
		for (int i = 0; i < n; ++i) {
			ans.push_back(s[i]);
		}
		return ans;
	}
};