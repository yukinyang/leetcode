#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

/*
���һȺǿ��׼��������С�����һ���±�� 0 ��ʼ���������� security ������ security[i] �ǵ� i ��ִ�ھ��������������Ӵ� 0 ��ʼ��š�ͬʱ����һ������ time ��

����� i �����������������������ǳ���Ϊһ���ʺϴ�����е����ӣ�

�� i ��ǰ�ͺ󶼷ֱ������� time �졣
�� i ��ǰ���� time �쾯����Ŀ���Ƿǵ����ġ�
�� i ������� time �쾯����Ŀ���Ƿǵݼ��ġ�
����ʽ�ģ��� i ����һ�����ʴ�����е����ӵ��ҽ�����security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].

���㷵��һ�����飬���� ���� �ʺϴ�����е����ӣ��±�� 0 ��ʼ�������ص����ӿ��� ���� ˳�����С�
*/

class Solution {
public:
	vector<int> goodDaysToRobBank(vector<int>& security, int time) {
		int n = security.size();
		vector<int> shun(n, 0);
		vector<int> fan(n, 0);
		vector<int> ans;
		int now = 0, fannow = 0;
		for (int i = 1; i < n - time; ++i) {
			if (security[i] <= security[i - 1]) {
				++now;
			}
			else {
				now = 0;
			}
			if (now >= time) {
				shun[i] = 1;
			}
			if (security[n - i - 1] <= security[n - i]) {
				++fannow;
			}
			else {
				fannow = 0;
			}
			if (fannow >= time) {
				fan[n - i - 1] = 1;
			}
		}
		if (time == 0) {
			shun[0] = 1;
			fan[0] = 1;
			shun[n - 1] = 1;
			fan[n - 1] = 1;
		}
		for (int i = 0; i < n; ++i) {
			if (shun[i] && fan[i]) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}