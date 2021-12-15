#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
给你一个字符串 s ，其中包含字母顺序打乱的用英文单词表示的若干数字（0-9）。按 升序 返回原始的数字。
*/

class Solution {
public:
	string originalDigits(string s) {
		string res = "";
		unordered_map<char, int> nums;
		for (char ch : s) {
			if (nums.find(ch) == nums.end()) {
				nums[ch] = 1;
			}
			else {
				++nums[ch];
			}
		}
		while (nums['z'] > 0) {
			res.push_back('0');
			--nums['z'];
			--nums['e'];
			--nums['r'];
			--nums['o'];
		}
		while (nums['x'] > 0) {
			res.push_back('6');
			--nums['s'];
			--nums['i'];
			--nums['x'];
		}
		while (nums['w'] > 0) {
			res.push_back('2');
			--nums['t'];
			--nums['w'];
			--nums['o'];
		}
		while (nums['g'] > 0) {
			res.push_back('8');
			--nums['e'];
			--nums['i'];
			--nums['g'];
			--nums['h'];
			--nums['t'];
		}
		while (nums['s'] > 0) {
			res.push_back('7');
			--nums['s'];
			--nums['e'];
			--nums['v'];
			--nums['e'];
			--nums['n'];
		}
		while (nums['h'] > 0) {
			res.push_back('3');
			--nums['t'];
			--nums['h'];
			--nums['r'];
			--nums['e'];
			--nums['e'];
		}
		while (nums['v'] > 0) {
			res.push_back('5');
			--nums['f'];
			--nums['i'];
			--nums['v'];
			--nums['e'];
		}
		while (nums['f'] > 0) {
			res.push_back('4');
			--nums['f'];
			--nums['o'];
			--nums['u'];
			--nums['r'];
		}
		while (nums['o'] > 0) {
			res.push_back('1');
			--nums['o'];
			--nums['n'];
			--nums['e'];
		}
		while (nums['i'] > 0) {
			res.push_back('9');
			--nums['n'];
			--nums['i'];
			--nums['n'];
			--nums['e'];
		}
		sort(res.begin(), res.end());
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}