#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
��дһ���������������ǽ�������ַ�����ת�����������ַ������ַ����� s ����ʽ������

��Ҫ�����������������Ŀռ䣬�����ԭ���޸��������顢ʹ�� O(1) �Ķ���ռ�����һ���⡣
*/

class Solution {
public:
	void reverseString(vector<char>& s) {
		int l = 0, r = s.size() - 1;
		while (l <= r) {
			swap(s[l], s[r]);
			++l;
			--r;
		}
	}
};