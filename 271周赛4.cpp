#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
��һ�����޵� x �������ϣ������ˮ���ֲ�������ĳЩλ�á�����һ����ά�������� fruits ������ fruits[i] = [positioni, amounti] ��ʾ���� amounti ��ˮ�������� positioni �ϡ�fruits �Ѿ��� positioni �������� ��ÿ�� positioni ������ͬ ��

������������� startPos �� k ���������λ�� startPos �����κ�λ�ã������ѡ�� ����������� �ߡ��� x ����ÿ�ƶ� һ����λ ���ͼ��� һ�� �����ܹ������� ��� k ������ÿ�ﵽһ��λ�ã�����ժ��ȫ����ˮ����ˮ��Ҳ���Ӹ�λ����ʧ��������������

���������ժ��ˮ���� ������� ��
*/

class Solution {
public:
	int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
		int ans = 0;
		int n = fruits.size();
		int l = startPos - k;
		int r = startPos + k;
		unordered_map<int, int> map;
		for (int i = 0; i < n; ++i) {
			//if(fruits[i][0] >= l && fruits[i][0] <= r)
			map[fruits[i][0]] = fruits[i][1];
		}
		vector<int> midl(k + 1, 0);
		vector<int> midr(k + 1, 0);
		int all_l = 0, all_r = 0;
		for (int i = 1; i < k + 1; ++i) {
			if (map.find(startPos - i) != map.end()) {
				all_l += map[startPos - i];
			}
			midl[i] = all_l;
			if (map.find(startPos + i) != map.end()) {
				all_r += map[startPos + i];
			}
			midr[i] = all_r;
		}
		for (int i = 0; i < k + 1; ++i) {
			int len_l = i;
			int len_r = k - i * 2;
			if (len_r < 0) {
				len_r = 0;
			}
			ans = max(ans, midl[len_l] + midr[len_r]);
		}
		for (int i = 0; i < k + 1; ++i) {
			int len_r = i;
			int len_l = k - i * 2;
			if (len_l < 0) {
				len_l = 0;
			}
			ans = max(ans, midl[len_l] + midr[len_r]);
		}
		if (map.find(startPos) != map.end()) {
			ans += map[startPos];
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}