#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

/*
����һ���ַ������� words ��ֻ���ؿ���ʹ���� ��ʽ���� ͬһ�е���ĸ��ӡ�����ĵ��ʡ���������ͼ��ʾ��

��ʽ���� �У�

��һ�����ַ� "qwertyuiop" ��ɡ�
�ڶ������ַ� "asdfghjkl" ��ɡ�
���������ַ� "zxcvbnm" ��ɡ�
*/

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> res;
		vector<string> hangs = { "qwertyuiop", "asdfghjkl","zxcvbnm" };
		unordered_map<char, int> zimu;
		for (int i = 0; i < hangs.size(); i++) {
			string hang = hangs[i];
			for (char ch : hang) {
				zimu[ch] = i;
				zimu[ch + 'A' - 'a'] = i;
			}
		}
		for (int i = 0; i < words.size(); i++) {
			string word = words[i];
			int first = zimu[word[0]];
			bool is = true;
			for (char ch : word) {
				if (zimu[ch] != first) {
					is = false;
					break;
				}
			}
			if (is) {
				res.push_back(word);
			}
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}