#include <iostream>
#include <string>

using namespace std;

/*
�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β����

�붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ����磬�����ַ���"abcdefg"������2���ú�������������ת��λ�õ��Ľ��"cdefgab"��
*/

class Solution {
public:
	string reverseLeftWords(string s, int n) {
		int len = s.size();
		string ans(s, n, len - 1);
		for (int i = 0; i < n; ++i) {
			ans.push_back(s[i]);
		}
		return ans;
	}
};