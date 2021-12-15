#include <iostream>
#include <vector>

using namespace std;

/*
������һ��m��n�еķ��񣬴����� [0,0] ������ [m-1,n-1] ��

һ�������˴����� [0, 0] �ĸ��ӿ�ʼ�ƶ�����ÿ�ο��������ҡ��ϡ����ƶ�һ�񣨲����ƶ��������⣩��Ҳ���ܽ�������������������λ֮�ʹ���k�ĸ��ӡ�

���磬��kΪ18ʱ���������ܹ����뷽�� [35, 37] ����Ϊ3+5+3+7=18���������ܽ��뷽�� [35, 38]����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�
*/

class Solution {
public:
	int res = 0;
	int movingCount(int m, int n, int k) {
		int h = 0, w = 0;
		vector<vector<int>> used(m, vector<int>(n, 0));
		dfs(used, h, w, k);
		return res;
	}

	int bit_val(int a) {
		return a % 10 + (a / 10) % 10 + a / 100;
	}

	void dfs(vector<vector<int>>& used, int h, int w, int k) {
		used[h][w] = 1;
		++res;
		if (h > 0 && used[h - 1][w] != 1 && (bit_val(h - 1) + bit_val(w)) <= k) {
			dfs(used, h - 1, w, k);
		}
		if (h < used.size() - 1 && used[h + 1][w] != 1 && (bit_val(h + 1) + bit_val(w)) <= k) {
			dfs(used, h + 1, w, k);
		}
		if (w < used[0].size() - 1 && used[h][w + 1] != 1 && (bit_val(h) + bit_val(w + 1)) <= k) {
			dfs(used, h, w + 1, k);
		}
		if (w > 0 && used[h][w - 1] != 1 && (bit_val(h) + bit_val(w - 1)) <= k) {
			dfs(used, h, w - 1, k);
		}
		return;
	}
};

int main() {
	Solution s;
	int m = 38;
	int n = 15;
	int k = 9;
	//int bits = 89;
	//cout << s.bit_val(bits) << endl;
	int res = s.movingCount(m, n, k);
	cout << res << endl;
	system("pause");
	return 0;
}