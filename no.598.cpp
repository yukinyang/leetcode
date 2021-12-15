#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给定一个初始元素全部为 0，大小为 m*n 的矩阵 M 以及在 M 上的一系列更新操作。

操作用二维数组表示，其中的每个操作用一个含有两个正整数 a 和 b 的数组表示，含义是将所有符合 0 <= i < a 以及 0 <= j < b 的元素 M[i][j] 的值都增加 1。

在执行给定的一系列操作后，你需要返回矩阵中含有最大整数的元素个数。
*/

class Solution {
public:
	int maxCount(int m, int n, vector<vector<int>>& ops) {
		int res = 0;
		int num = ops.size(), minh = 40001, minw = 40001;
		if (num == 0) {
			return res;
		}
		for (int i = 0; i < num; ++i) {
			int h = ops[i][0], w = ops[i][1];
			minh = min(minh, h);
			minw = min(minw, w);
		}
		res = minw * minh;
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}