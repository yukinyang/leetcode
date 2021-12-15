#include <iostream>

using namespace std;

/*
ʵ�� pow(x, n) �������� x �� n ���ݺ���������xn��������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣
*/

class Solution {
public:
	double myPow(double x, int n) {
		if (n == INT_MIN) {
			return (1 / x) * myPow(x, n + 1);
		}
		if (n == 0) {
			return 1;
		}
		if (n < 0) {
			n = abs(n);
			x = 1 / x;
		}
		double res = 1;
		while (n) {
			if (n % 2) {
				res *= x;
			}
			x *= x;
			n /= 2;
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}