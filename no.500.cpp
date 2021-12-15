#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
给你一个字符串数组 words ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

美式键盘 中：

第一行由字符 "qwertyuiop" 组成。
第二行由字符 "asdfghjkl" 组成。
第三行由字符 "zxcvbnm" 组成。
*/

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> res;
		vector<string> hangs = { "qwertyuiop", "asdfghjkl","zxcvbnm" };
		unordered_map<char, int> zimu;
		for (int i = 0; i < hangs.size(); i++) {
			string hang = hangs[i];
			for (char ch : hang) {
				zimu[ch] = i;
				zimu[ch + 'A' - 'a'] = i;
			}
		}
		for (int i = 0; i < words.size(); i++) {
			string word = words[i];
			int first = zimu[word[0]];
			bool is = true;
			for (char ch : word) {
				if (zimu[ch] != first) {
					is = false;
					break;
				}
			}
			if (is) {
				res.push_back(word);
			}
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}