#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int ans = 0;
		queue<char> q;
		unordered_map<char, int> map;
		int n = s.size();
		for (int i = 0; i < n; ++i) {
			// int mid = q.size();
			q.push(s[i]);
			++map[s[i]];
			// ++mid;
			if (map[s[i]] == 2) {
				while (map[s[i]] == 2) {
					char out = q.front();
					q.pop();
					--map[out];
					// --mid;
				}
			}
			ans = max(ans, int(q.size()));
		}
		return ans;
	}
};