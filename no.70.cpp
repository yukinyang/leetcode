#include <iostream>
#include <vector>

using namespace std;

/*
������������¥�ݡ���Ҫ n ������ܵ���¥����

ÿ��������� 1 �� 2 ��̨�ס����ж����ֲ�ͬ�ķ�����������¥���أ�

ע�⣺���� n ��һ����������
*/

class Solution {
public:
	int climbStairs(int n) {
		/* dp */
		//vector<int> dp(n + 1, 1);
		//for (int i = 2; i <= n; ++i) {
		//	dp[i] = dp[i - 2] + dp[i - 1];
		//}
		//return dp[n];

		/* dp ��ʡ�ռ� */
		int ans = 1;
		int fir = 0, sec = 1;
		for (int i = 1; i <= n; ++i) {
			ans = fir + sec;
			fir = sec;
			sec = ans;
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}