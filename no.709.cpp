#include <iostream>
#include <string>

using namespace std;

/*
����һ���ַ��� s �������ַ����еĴ�д��ĸת������ͬ��Сд��ĸ�������µ��ַ�����
*/

class Solution {
public:
	string toLowerCase(string s) {
		int n = s.size();
		for (int i = 0; i <= n; ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] -= ('A' - 'a');
			}
		}
		return s;
	}
};