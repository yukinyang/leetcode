#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
在二维数组grid中，grid[i][j]代表位于某处的建筑物的高度。 我们被允许增加任何数量（不同建筑物的数量可能不同）的建筑物的高度。 高度 0 也被认为是建筑物。

最后，从新数组的所有四个方向（即顶部，底部，左侧和右侧）观看的“天际线”必须与原始数组的天际线相同。 
城市的天际线是从远处观看时，由所有建筑物形成的矩形的外部轮廓。 请看下面的例子。

建筑物高度可以增加的最大总和是多少？
*/

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		int ans = 0;
		int h = grid.size(), w = grid[0].size();
		vector<int> h_max(h, 0), w_max(w, 0);
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				w_max[j] = max(w_max[j], grid[i][j]);
				h_max[i] = max(h_max[i], grid[i][j]);
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				ans += (min(w_max[j], h_max[i]) - grid[i][j]);
			}
		}
		return ans;
	}
};