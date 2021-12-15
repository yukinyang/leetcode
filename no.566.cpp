#include <iostream>
#include <vector>

using namespace std;

/*
在 MATLAB 中，有一个非常有用的函数 reshape ，它可以将一个 m x n 矩阵重塑为另一个大小不同（r x c）的新矩阵，但保留其原始数据。

给你一个由二维数组 mat 表示的 m x n 矩阵，以及两个正整数 r 和 c ，分别表示想要的重构的矩阵的行数和列数。

重构后的矩阵需要将原始矩阵的所有元素以相同的 行遍历顺序 填充。

如果具有给定参数的 reshape 操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。
*/

class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
		if (r * c != mat.size() * mat[0].size()) {
			return mat;
		}
		int m = mat.size(), n = mat[0].size();
		vector<vector<int>> ans(r, vector<int>(c, 0));
		for (int i = 0; i < r * c; ++i) {
			int h = i / n, w = i % n;
			int newh = i / c, neww = i % c;
			ans[newh][neww] = mat[h][w];
		}
		return ans;
	}
};