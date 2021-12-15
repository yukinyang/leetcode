#include <iostream>
#include <vector>

using namespace std;

/*
给你一个 m x n 的二元矩阵 matrix ，且所有值被初始化为 0 。
请你设计一个算法，随机选取一个满足 matrix[i][j] == 0 的下标 (i, j) ，并将它的值变为 1 。
所有满足 matrix[i][j] == 0 的下标 (i, j) 被选取的概率应当均等。

尽量最少调用内置的随机函数，并且优化时间和空间复杂度。

实现 Solution 类：

Solution(int m, int n) 使用二元矩阵的大小 m 和 n 初始化该对象
int[] flip() 返回一个满足 matrix[i][j] == 0 的随机下标 [i, j] ，并将其对应格子中的值变为 1
void reset() 将矩阵中所有的值重置为 0
*/

class Solution {
public:
	vector<vector<int>> mat;
	Solution(int m, int n) {
		vector<vector<int>> mat_inside(m, vector<int>(n, 0));
		mat = mat_inside;
	}

	vector<int> flip() {
		int i, j;
		vector<int> res;
		int m = mat.size();
		int n = mat[0].size();
		i = rand() % m + 1;
		j = rand() % n + 1;
		while (mat[i][j] == 1) {
			i = rand() % m + 1;
			j = rand() % n + 1;
		}
		mat[i][j] = 1;
		res.push_back(i);
		res.push_back(j);
		return res;
	}

	void reset() {
		int m = mat.size();
		int n = mat[0].size();
		vector<vector<int>> mat_inside(m, vector<int>(n, 0));
		mat = mat_inside;
	}
};