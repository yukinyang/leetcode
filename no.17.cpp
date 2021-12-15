#include <iostream>
#include <vector>

using namespace std;

/*
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
*/

class Solution {
public:
	vector<string> n2d = { "abc", "def", "ghi","jkl", "mno", "pqrs","tuv", "wxyz" };
	vector<string> anss;
	vector<string> letterCombinations(string digits) {
		string ans = "";
		if (digits.size() == 0) {
			return anss;
		}
		dfs(digits, ans, 0);
		return anss;
	}

	void dfs(string digits, string ans, int now) {
		if (ans.size() == digits.size()) {
			anss.push_back(ans);
			return;
		}
		for (char ch : n2d[digits[now] - '2']) {
			ans.push_back(ch);
			dfs(digits, ans, now + 1);
			ans.pop_back();
		}
	}
};

int main() {
	system("pause");
	return 0;
}