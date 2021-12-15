#include <iostream>
#include <math.h>

using namespace std;

/*

*/

class Solution {
public:
	bool isPerfectSquare(int num) {
		/* 使用sqrt */
		//if (int(sqrt(num)) * int(sqrt(num)) != num) {
		//	return false;
		//}
		//return true;

		/* 不使用sqrt 二分*/
		int left = 0, right = num;
		double s;
		while (left <= right) {
			int mid = (right - left) / 2 + left;   // 这里要注意不能right + left，会超过int范围
			s = (double) mid * mid;                   // 这里要转换成double
			if (s == num) {
				return true;
			}
			else if (s > num) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		return false;
	}
};

int main() {
	Solution s;
	cout << boolalpha << s.isPerfectSquare(INT_MAX) << endl;
	system("pause");
	return 0;
}