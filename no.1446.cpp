#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
����һ���ַ��� s ���ַ����ġ�����������Ϊ��ֻ����һ���ַ�����ǿ����ַ����ĳ��ȡ�

���㷵���ַ�����������
*/

class Solution {
public:
	int maxPower(string s) {
		int ans = 1;
		int mid = 1;
		bool get = false;
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] != s[i - 1]) {
				ans = max(ans, mid);
				mid = 1;
				get = false;
			}
			if (get == false && s[i] == s[i - 1]) {
				get = true;
				mid = 2;
				continue;
			}
			if (get && s[i] == s[i - 1]) {
				++mid;
			}
		}
		ans = max(ans, mid);
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}