#include <iostream>
#include <vector>

using namespace std;

/*
给你一个大小为 m x n 的整数矩阵 grid ，表示一个网格。另给你三个整数 row、col 和 color 。网格中的每个值表示该位置处的网格块的颜色。

当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一 连通分量 。

连通分量的边界 是指连通分量中的所有与不在分量中的网格块相邻（四个方向上）的所有网格块，或者在网格的边界上（第一行/列或最后一行/列）的所有网格块。

请你使用指定颜色 color 为所有包含网格块 grid[row][col] 的 连通分量的边界 进行着色，并返回最终的网格 grid 。
*/

class Solution {
public:
	vector<vector<int>> borders;
	vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
		vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
		dfs(grid, row, col, visited);
		for (vector<int> mid : borders) {
			grid[mid[0]][mid[1]] = color;
		}
		return grid;
	}

	void dfs(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& visited) {
		vector<int> mid(2, 0);
		mid[0] = row;
		mid[1] = col;
		cout << mid[0] << ' ' << mid[1] << endl;
		visited[row][col] = 1;
		if (row > 0 && grid[row][col] == grid[row - 1][col] && visited[row - 1][col] == 0) {
			dfs(grid, row - 1, col, visited);
		}
		if (row < grid.size() - 1 && grid[row][col] == grid[row + 1][col] && visited[row][col + 1] == 0) {
			dfs(grid, row + 1, col, visited);
		}
		if (col > 0 && grid[row][col] == grid[row][col - 1] && visited[row][col - 1] == 0) {
			dfs(grid, row, col - 1, visited);
		}
		if (col < grid[0].size() - 1 && grid[row][col] == grid[row][col + 1] && visited[row][col + 1] == 0) {
			dfs(grid, row, col + 1, visited);
		}

		if (row == 0 || grid[row][col] != grid[row - 1][col]) {
			borders.push_back(mid);
			return;
		}
		else if (row == grid.size() - 1 || grid[row][col] != grid[row + 1][col]) {
			borders.push_back(mid);
			return;
		}
		else if (col == 0 || grid[row][col] != grid[row][col - 1]) {
			borders.push_back(mid);
			return;
		}
		else if (col == grid[0].size() - 1 || grid[row][col] != grid[row][col + 1]) {
			borders.push_back(mid);
			return;
		}
	}
};

int main() {
	Solution s;
	int r = 0, c = 0;
	cout << "Enter r: ";//规定二维数组行数
	cin >> r;
	cout << "Enter c: ";//规定二维数组列数
	cin >> c;
	vector<vector<int>>array;//定义二维数组
	vector<int>v;//定义一维数组
	array.clear();//将二维数组清空，或初始化（初始化代码很简单，不会可以百度）//也可不用这一步
	int temp = 0;
	for (int i = 0; i < r; i++)//输入r*c的二维数组
	{
		v.clear();//子数组返回时要清除
		for (int j = 0; j < c; j++)
		{
			cin >> temp;
			v.push_back(temp);

		}
		array.push_back(v);
	}
	//for (int i = 0; i < r; i++)//打印输入的二维数组
	//{
	//	for (int j = 0; j < c; j++)
	//	{
	//		cout << array[i][j] << " ";

	//	}
	//	printf("\n");
	//}
	s.colorBorder(array, 5, 3, 2);
	system("pause");
	return 0;
}