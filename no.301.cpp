#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
给你一个由若干括号和字母组成的字符串 s ，删除最小数量的无效括号，使得输入的字符串有效。

返回所有可能的结果。答案可以按 任意顺序 返回。

输入：s = "()())()"

输出：["(())()","()()()"]
*/

class Solution {
public:

	vector<string> res;

	vector<string> removeInvalidParentheses(string s) {
		vector<int> del = deletenum(s);
		int del_l = del[0];
		int del_r = del[1];
		cout << del_l << endl;
		cout << del_r << endl;
		get_res(s, 0, del_l, del_r, 0, 0);
		return res;
	}

	void get_res(string s, int now, int del_l, int del_r, int num_l, int num_r) {
		if (del_l == 0 && del_r == 0) {
			vector<int> isvalid = deletenum(s);
			if (isvalid[0] == 0 && isvalid[1] == 0) {
				res.push_back(s);
			}
		}
		for (int i = now; i < s.size(); i++) {
			if (i != now && s[i] == s[i - 1]) {
				if (s[i] == '(') num_l++;
				else if (s[i] == ')') num_r++;
				continue;
			}
			if (del_l + del_r > s.size() - i) {
				return;
			}
			if (s[i] == '('  && del_l > 0) {
				get_res(s.substr(0, i) + s.substr(i + 1), i, del_l - 1, del_r, num_l, num_r);
			}
			else if (s[i] == ')'  && del_r > 0) {
				get_res(s.substr(0, i) + s.substr(i + 1), i, del_l, del_r - 1, num_l, num_r);
			}
			if (s[i] == '(') {
				++num_l;
			}
			else if (s[i] == ')') {
				++num_r;
			}
			if (num_r > num_l) {
				return;
			}
		}
	}

	vector<int> deletenum(string s) {
		vector<int> res(4, 0);
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') {
				++res[2];
				++res[0];
			}
			else if (s[i] == ')') {
				++res[3];
				if (res[0] != 0) {
					--res[0];
				}
				else {
					++res[1];
				}
			}
		}
		return res;
	}
};

int main() {
	string input = ")(()";
	Solution s;
	vector<string> output = s.removeInvalidParentheses(input);
	cout << output.size() << endl;
	for (int i = 0; i < output.size(); i ++) {
		string res = output[i];
		cout << res << endl;
	}
	system("pause");
	return 0;
}


