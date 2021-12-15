#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

/*
����ַ������ҳ�һ����Ĳ������ظ��ַ������ַ��������������ַ����ĳ��ȡ�
*/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> count;
		queue<char> q;
		int res = 0;
		for (int i = 0; i < s.size(); ++i) {
			q.push(s[i]);
			if (count.find(s[i]) == count.end()) {
				count[s[i]] = 1;
			}
			else {
				++count[s[i]];
			}
			if (count[s[i]] > 1) {
				while (q.front() != s[i]) {
					char fro = q.front();
					q.pop();
					--count[fro];
				}
				q.pop();
				--count[s[i]];
			}
			int length = q.size();
			res = max(res, length);
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}