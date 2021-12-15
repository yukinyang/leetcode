#include <iostream>
#include <vector>

using namespace std;

/*
请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
*/

class Solution {
public:
	bool isMatch(string s, string p) {
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		dp[0][0] = true;
		for (int j = 2; j <= p.size(); ++j) {
			if (p[j - 1] == '*') {
				dp[0][j] = dp[0][j - 2];
			}
		}
		for (int i = 1; i <= s.size(); ++i) {
			for (int j = 1; j <= p.size(); ++j) {
				if (p[j - 1] == '*') {
					//cout << 999 << endl;
					dp[i][j] = (dp[i][j - 2]) || (dp[i - 1][j] && s[i - 1] == p[j - 2]) || (dp[i - 1][j] && p[j - 2] == '.');
				}
				else {
					dp[i][j] = (dp[i - 1][j - 1] && p[j - 1] == '.') || (dp[i - 1][j - 1] && p[j - 1] == s[i - 1]);
				}
			}
		}
		for (int i = 0; i < dp.size(); ++i) {
			for (int j = 0; j < dp[0].size(); ++j) {
				cout << dp[i][j] << ' ';
			}
			cout << endl;
		}
		return dp[s.size()][p.size()];
	}
};

int main() {
	Solution S;
	string s = "aa";
	string p = "a*";
	S.isMatch(s, p);
	system("pause");
	return 0;
}