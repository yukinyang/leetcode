#include <iostream>
#include <vector>

using namespace std;

/*
����һ���ַ��� s�������ɵ�����ɣ�����ǰ����һЩ�ո��ַ������������ַ��������һ�����ʵĳ��ȡ�

���� ��ָ������ĸ��ɡ��������κοո��ַ���������ַ�����
*/

class Solution {
public:
	int lengthOfLastWord(string s) {
		int ans = 0;
		bool getword = false;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (getword == false && s[i] != ' ') {
				ans = 1;
				getword = true;
				continue;
			}
			if (getword && s[i] != ' ') {
				++ans;
			}
			else if (getword && s[i] == ' ') {
				return ans;
			}
		}
		return ans;
	}
};

int main() {
	return  0;
}