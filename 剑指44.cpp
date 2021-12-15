#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

请写一个函数，求任意第n位对应的数字。
*/

class Solution {
public:
	int findNthDigit(int n) {
		if (n <= 9) {
			return n;
		}
		double last = 9;
		int i = 1;
		double bits = 9;
		while (n > bits) {
			++i;
			last += 90 * pow(10, i - 2);
			bits += i * 90 * pow(10, i - 2);
		}
		bits -= i * 90 * pow(10, i - 2);
		last -= 90 * pow(10, i - 2);
		int newbits = bits;
		int newlast = last;
		cout << "是 " << i << " 位数" << endl;
		int more = (n - newbits) / i;
		int yu = (n - newbits) % i;
		cout << yu << endl;
		if (yu == 0) {
			cout << "当前数字是 " << more + newlast << endl;
			return (more + newlast) % 10;
		}
		else {
			int now_num = more + newlast + 1;
			cout << "当前数字是 " << now_num << endl;
			now_num /= pow(10, i - yu);
			return now_num % 10;
		}
	}
};

int main() {
	Solution s;
	cout << s.findNthDigit(INT_MAX) << endl;
	system("pause");
	return 0;
}