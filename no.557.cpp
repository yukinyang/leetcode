#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
*/

class Solution {
public:
	string reverseWords(string s) {
		string ans = "";
		string word = "";
		s += " ";
		for (char ch : s) {
			if (ch == ' ') {
				reverse(word);
				ans += " ";
				ans += word;
				word = "";
			}
			word.push_back(ch);
		}
		ans.pop_back();
		return ans;
	}

	void reverse(string word) {
		int l = 0, r = word.size() - 1;
		while (l <= r) {
			swap(word[l], word[r]);
			--r;
			++l;
		}
	}
};

/* 双指针 */
class Solution {
public:
	string reverseWords(string s) {
		int l = 0, r = 0;
		s += " ";
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == ' ') {
				r = i - 1;
				while (l <= r) {
					swap(s[l], s[r]);
					++l;
					--r;
				}
				l = i + 1;
				r = l;
			}
		}
		return s;
	}
};