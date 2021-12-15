#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

/*
你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：

写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：

猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls", 公牛），
有多少位属于数字猜对了但是位置不对（称为 "Cows", 奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。

提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。

请注意秘密数字和朋友猜测的数字都可能含有重复数字。
*/

class Solution {
public:
	string getHint(string secret, string guess) {
		unordered_map<char, int> sec;
		string res;
		int bull = 0, cow = 0;
		for (char ch : secret) {
			if (sec.find(ch) == sec.end()) {
				sec[ch] = 1;
			}
			else {
				++sec[ch];
			}
		}
		for (int i = 0; i < guess.size(); ++i) {
			char ch = guess[i];
			if (ch == secret[i]) {
				++bull;
				if (sec[ch] == 0) {
					--cow;
				}
				else {
					--sec[ch];
				}
			}
			else if (sec.find(ch) != sec.end() && sec[ch] != 0) {
				++cow;
				--sec[ch];
			}
		}
		string r1 = to_string(bull);
		string r2 = to_string(cow);
		res += r1;
		res.push_back('A');
		res += r2;
		res.push_back('B');
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}