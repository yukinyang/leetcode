#include <iostream>

using namespace std;

/*
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
*/

class Solution {
public:
	int countDigitOne(int n) {
		long res = 0, digit = 1, low = 0;
		while (n) {
			int cur = n % 10;
			n /= 10;
			if (cur > 1) {
				res += (digit * n + digit);
			}
			else if (cur == 1) {
				res += (digit * n + low + 1);
			}
			else if(cur == 0) {
				res += n * digit;
			}
			low += cur * digit;
			digit *= 10;
			cout << res << endl;
		}
		return res;
	}
};

int main() {
	Solution s;
	int res = s.countDigitOne(111111111);
	system("pause");
	return 0;
}