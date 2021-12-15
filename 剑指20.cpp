#include <iostream>
#include <string>

using namespace std;

/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

数值（按顺序）可以分成以下几个部分：

若干空格
一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
若干空格
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分数值列举如下：
["+100", "5e2", "-123", "3.1416", "-1E-16", "0123"]
部分非数值列举如下：
["12e", "1a3.14", "1.2.3", "+-5", "12e+5.4"]
*/

class Solution {
public:
	bool isNumber(string s) {
		while (s.size() && s[s.size() - 1] == ' ') {
			s.pop_back();
		}
		string news;
		bool start = false;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] != ' ') {
				start = true;
			}
			if (start) {
				news.push_back(s[i]);
			}
		}
		return is_zheng(news) || is_xiao(news) || is_e(news);
	}

	bool is_zheng(string num) {
		int i = 0;
		bool res = false;
		if (num[0] == '+' || num[0] == '-') {
			++i;
		}
		for (int n = i; n < num.size(); ++n) {
			if (num[n] - '0' <= 10 && num[n] - '0' >= 0) {
				res = res || true;
			}
			else {
				return false;
			}
		}
		cout << 1 << boolalpha << res << endl;
		return res;
	}

	bool is_xiao(string num) {
		if (num[0] == '+' || num[0] == '-') {
			string newnum(num, 1);
			return is_xiao(newnum);
		}
		string fir;
		string sec;
		bool getdot = false;
		for (int i = 0; i < num.size(); ++i) {
			if (num[i] == '.' && getdot == false) {
				getdot = true;
				continue;
			}
			if (getdot == false) {
				fir.push_back(num[i]);
			}
			else {
				sec.push_back(num[i]);
			}
		}
		//cout << fir << endl;
		//cout << sec << endl;
		if (sec != "" && (sec[0] == '+' || sec[0] == '-')) {
			return false;
		}
		bool res = (sec == "" && is_zheng(fir)) || (is_zheng(fir) && is_zheng(sec)) || (fir == "" && is_zheng(sec));
		cout << 2 << boolalpha << res << endl;
		return res;
	}

	bool is_e(string num) {
		if (num[0] == '+' || num[0] == '-') {
			string newnum(num, 1);
			return is_e(newnum);
		}
		string fir;
		string sec;
		bool gete = false;
		for (int i = 0; i < num.size(); ++i) {
			if ((num[i] == 'e' || num[i] == 'E') && gete == false) {
				gete = true;
				continue;
			}
			if (gete == false) {
				fir.push_back(num[i]);
			}
			else {
				sec.push_back(num[i]);
			}
		}
		cout << fir << endl;
		cout << sec << endl;
		bool res = is_zheng(sec) && (is_zheng(fir) || is_xiao(fir));
		cout << 3 << boolalpha << res << endl;
		return res;
	}
};

int main() {
	Solution s;
	string test = "6ee69";
	cout << boolalpha << s.isNumber(test) << endl;
	system("pause");
	return 0;
}