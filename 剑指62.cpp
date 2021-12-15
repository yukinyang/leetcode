#include <iostream>
#include <vector>

using namespace std;

/*
0,1,������,n-1��n�������ų�һ��ԲȦ��������0��ʼ��ÿ�δ����ԲȦ��ɾ����m�����֣�ɾ�������һ�����ֿ�ʼ��������������ԲȦ��ʣ�µ����һ�����֡�

���磬0��1��2��3��4��5���������һ��ԲȦ��������0��ʼÿ��ɾ����3�����֣���ɾ����ǰ4������������2��0��4��1��������ʣ�µ�������3��
*/

class Solution {
public:
	int lastRemaining(int n, int m) {
		if (n == 0) {
			return 0;
		}
		return (lastRemaining(n - 1, m) + m) % n;
	}
	int lastRemaining_for(int n, int m) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res = (res + m) % i;
		}
		return res;
	}
};

int main() {
	int n, m;
	n = 5;
	m = 3;
	Solution s;
	int res = s.lastRemaining_for(n, m);
	cout << res << endl;
	system("pause");
	return 0;
}