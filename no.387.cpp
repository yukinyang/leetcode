#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
����һ���ַ������ҵ����ĵ�һ�����ظ����ַ���������������������������ڣ��򷵻� -1��
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