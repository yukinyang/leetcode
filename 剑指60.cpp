#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。
*/

class Solution {
public:
	vector<double> dicesProbability(int n) {
		vector<double> res(6, 1.0 / 6.0);
		for (int i = 2; i <= n; ++i) {
			vector<double> mid(5 * i + 1, 0);
			for (int j = 0; j < 5 * i + 1; ++j) {
				for (int m = 0; m < 6; ++m) {
					if ((j - m) >= 0 && (j - m) < (5 * i - 4)) {
						mid[j] += res[j - m] * (1.0 / 6.0);
					}
				}
			}
			res = mid;
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<double> res = s.dicesProbability(5);
	for (double db : res) {
		cout << db << endl;
	}
	//cout << s.C(3, 9) << endl;
	system("pause");
	return 0;
}