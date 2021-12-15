#include <iostream>

using namespace std;

/*
����һ������ n ����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�����

���磬����12��1��12��Щ�����а���1 ��������1��10��11��12��1һ��������5�Ρ�
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