#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
��n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s�����п��ܵ�ֵ���ֵĸ��ʡ�

 ����Ҫ��һ�����������鷵�ش𰸣����е� i ��Ԫ�ش����� n ���������������ĵ��������е� i С���Ǹ��ĸ��ʡ�
*/

class Solution {
public:
	vector<double> dicesProbability(int n) {
		vector<double> res(6, 1.0 / 6.0);
		for (int i = 2; i <= n; ++i) {
			vector<double> mid(5 * i + 1, 0);
			for (int j = 0; j < 5 * i + 1; ++j) {
				for (int m = 0; m < 6; ++m) {
					if ((j - m) >= 0 && (j - m) < (5 * i - 4)) {
						mid[j] += res[j - m] * (1.0 / 6.0);
					}
				}
			}
			res = mid;
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<double> res = s.dicesProbability(5);
	for (double db : res) {
		cout << db << endl;
	}
	//cout << s.C(3, 9) << endl;
	system("pause");
	return 0;
}