#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
句子 是一个单词列表，列表中的单词之间用单个空格隔开，且不存在前导或尾随空格。每个单词仅由大小写英文字母组成（不含标点符号）。

例如，"Hello World"、"HELLO" 和 "hello world hello world" 都是句子。
给你一个句子 s​​​​​​ 和一个整数 k​​​​​​ ，请你将 s​​ 截断 ​，​​​使截断后的句子仅含 前 k​​​​​​ 个单词。返回 截断 s​​​​​​ 后得到的句子。
*/

class Solution {
public:
	string truncateSentence(string s, int k) {
		s.push_back(' ');
		string ans;
		for (char ch : s) {
			if (ch == ' ') {
				--k;
			}
			if (k == 0) {
				break;
			}
			ans.push_back(ch);
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}