#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
����һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��
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

/* ˫ָ�� */
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