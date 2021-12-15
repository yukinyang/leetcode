#include <iostream>

using namespace std;

/*
쳲���������ͨ���� F(n) ��ʾ���γɵ����г�Ϊ 쳲��������� ���������� 0 �� 1 ��ʼ�������ÿһ�����ֶ���ǰ���������ֵĺ͡�

���� n ������� F(n)��
*/

class Solution {
public:
	int fib(int n) {
		if (n <= 1) {
			return n;
		}
		int ans;
		int fir = 0, sec = 1;
		for (int i = 2; i <= n; ++i) {
			ans = (fir + sec);
			fir = sec;
			sec = ans;
		}
		return ans;
	}
};