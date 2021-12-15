#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
*/

class Solution {
public:
	string convert(string s, int numRows) {
		string ans = "";
		vector<string> ans_parts(numRows, "");
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			int now = i - (i / (2 * numRows - 2)) * (2 * numRows - 2);
			cout << now << endl;
			if (now < numRows) {
				ans_parts[now % numRows].push_back(s[i]);
			}
			else {
				ans_parts[2 * numRows - 2 - now].push_back(s[i]);
			}
		}
		for (string part : ans_parts) {
			ans += part;
		}
		return ans;
	}
};

int main() {
	Solution s;
	s.convert("PAYPALISHIRING", 3);
	system("pause");
	return 0;
}