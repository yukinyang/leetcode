#include <iostream>
#include <vector>

using namespace std;

/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。

一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。

例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
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