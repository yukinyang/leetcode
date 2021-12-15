#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
*/

class Solution {
public:
	int firstUniqChar(string s) {
		vector<int> letter(26, 0);
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			++letter[s[i] - 'a'];
		}
		for (int i = 0; i < n; ++i) {
			if (letter[s[i] - 'a'] == 1) {
				return i;
			}
		}
		return -1;
	}
};