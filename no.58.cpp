#include <iostream>
#include <vector>

using namespace std;

/*
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。返回字符串中最后一个单词的长度。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。
*/

class Solution {
public:
	int lengthOfLastWord(string s) {
		int ans = 0;
		bool getword = false;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (getword == false && s[i] != ' ') {
				ans = 1;
				getword = true;
				continue;
			}
			if (getword && s[i] != ' ') {
				++ans;
			}
			else if (getword && s[i] == ' ') {
				return ans;
			}
		}
		return ans;
	}
};

int main() {
	return  0;
}