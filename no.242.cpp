#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
*/

class Solution {
public:
	bool isAnagram(string s, string t) {
		unordered_map<char, int> map;
		int n1 = s.size(), n2 = t.size();
		if (n1 != n2) {
			return false;
		}
		for (char ch : s) {
			++map[ch];
		}
		for (char ch : t) {
			--map[ch];
			if (map[ch] < 0) {
				return false;
			}
		}
		return true;
	}
};