#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

/*
������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����������У���5λ�����±�0��ʼ��������5����13λ��1����19λ��4���ȵȡ�

��дһ���������������nλ��Ӧ�����֡�
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
		cout << "�� " << i << " λ��" << endl;
		int more = (n - newbits) / i;
		int yu = (n - newbits) % i;
		cout << yu << endl;
		if (yu == 0) {
			cout << "��ǰ������ " << more + newlast << endl;
			return (more + newlast) % 10;
		}
		else {
			int now_num = more + newlast + 1;
			cout << "��ǰ������ " << now_num << endl;
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