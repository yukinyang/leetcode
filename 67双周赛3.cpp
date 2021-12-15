#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

/*
����һ��ը���б�һ��ը���� ��ը��Χ ����Ϊ��ը��ΪԲ�ĵ�һ��Բ��

ը����һ���±�� 0 ��ʼ�Ķ�ά�������� bombs ��ʾ������ bombs[i] = [xi, yi, ri] ��xi �� yi ��ʾ�� i ��ը���� X �� Y ���꣬ri ��ʾ��ը��Χ�� �뾶 ��

����Ҫѡ������ һ�� ը���������ը��������ʱ������ ������ը��Χ�ڵ�ը�����ᱻ��������Щը�����һ�������Ǳ�ը��Χ�ڵ�����ը��������

�������� bombs �����㷵�������� һ�� ը����ǰ���£���� ��������ը����Ŀ��
*/

class Solution {
public:
	int maximumDetonation(vector<vector<int>>& bombs) {
		vector<int> father;
		int n = bombs.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int now = 0;
			int x = bombs[i][0];
			int y = bombs[i][1];
			int r = bombs[i][2];
			for (int j = 0; j < n; ++j) {
				if (i == j) {
					continue;
				}
				int jx = bombs[j][0];
				int jy = bombs[j][1];
				if (r >= sqrt(double(jx - x) * double(jx - x) + double(jy - y) * double(jy - y))) {
					++now;
				}
			}
			father.push_back(now);
			ans = max(ans, now);
		}
		for (int i = 0; i < n; ++i) {
			int now = 0;
			int x = bombs[i][0];
			int y = bombs[i][1];
			int r = bombs[i][2];
			for (int j = 0; j < n; ++j) {
				if (i == j) {
					continue;
				}
				int jx = bombs[j][0];
				int jy = bombs[j][1];
				if (r >= sqrt(double(jx - x) * double(jx - x) + double(jy - y) * double(jy - y))) {
					now += father[j];
				}
			}
			ans = max(ans, now);
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}