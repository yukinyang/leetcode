#include <iostream>
#include <vector>

using namespace std;

/*
��ʵ��һ����������ƥ�����'. '��'*'��������ʽ��ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ���0�Σ���
�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ�����磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬����"aa.a"��"ab*a"����ƥ�䡣
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