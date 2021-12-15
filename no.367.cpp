#include <iostream>
#include <math.h>

using namespace std;

/*

*/

class Solution {
public:
	bool isPerfectSquare(int num) {
		/* ʹ��sqrt */
		//if (int(sqrt(num)) * int(sqrt(num)) != num) {
		//	return false;
		//}
		//return true;

		/* ��ʹ��sqrt ����*/
		int left = 0, right = num;
		double s;
		while (left <= right) {
			int mid = (right - left) / 2 + left;   // ����Ҫע�ⲻ��right + left���ᳬ��int��Χ
			s = (double) mid * mid;                   // ����Ҫת����double
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