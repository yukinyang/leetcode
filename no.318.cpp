#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
给定一个字符串数组 words，找到 length(word[i]) * length(word[j]) 的最大值，并且这两个单词不含有公共字母。

你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。
*/

class Solution {
public:
	int maxProduct(vector<string>& words) {
		int res = 0;
		unordered_map<char, bool> letter;
		while (words.size() > 1) {
			string word = words[words.size() - 1];
			for (char ch : word) {
				letter[ch] = true;
			}
			for (int i = 0; i < words.size() - 1; ++i) {
				string now = words[i];
				int ok = 1;
				for (char ch : now) {
					if (letter.find(ch) != letter.end()) {
						ok = 0;
						break;
					}
				}
				int r = word.size() * ok * now.size();
				res = max(res, r);
			}
			words.pop_back();
			letter.clear();
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<string> words = { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" };
	cout << s.maxProduct(words) << endl;
	system("pause");
	return 0;
}