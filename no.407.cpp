#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

/*
给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，请计算图中形状最多能接多少体积的雨水。
*/

class Solution {
public:
	int trapRainWater(vector<vector<int>>& heightMap) {
		int m = heightMap.size(), n = heightMap[0].size();
		int maxHeight = 0;
		int dirs[] = { -1, 0, 1, 0, -1 };

		for (int i = 0; i < m; ++i) {
			maxHeight = max(maxHeight, *max_element(heightMap[i].begin(), heightMap[i].end()));
		}
		vector<vector<int>> water(m, vector<int>(n, maxHeight));
		queue<pair<int, int>> qu;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
					if (water[i][j] > heightMap[i][j]) {
						water[i][j] = heightMap[i][j];
						qu.push(make_pair(i, j));
					}
				}
			}
		}
		while (!qu.empty()) {
			int x = qu.front().first, y = qu.front().second;
			qu.pop();
			for (int i = 0; i < 4; ++i) {
				int nx = x + dirs[i], ny = y + dirs[i + 1];
				if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
					continue;
				}
				if (water[x][y] < water[nx][ny] && water[nx][ny] > heightMap[nx][ny]) {
					water[nx][ny] = max(water[x][y], heightMap[nx][ny]);
					qu.push(make_pair(nx, ny));
				}
			}
		}

		int res = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				res += water[i][j] - heightMap[i][j];
			}
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}