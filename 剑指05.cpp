#include <iostream>
#include <string>

using namespace std;

/*
��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��
*/

class Solution {
public:
	string replaceSpace(string s) {
		string ans;
		for (char ch : s) {
			if (ch == ' ') {
				ans += "%20";
			}
			else {
				ans.push_back(ch);
			}
		}
		return ans;
	}
};