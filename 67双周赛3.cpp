#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>

using namespace std;

/*
给你一个炸弹列表。一个炸弹的 爆炸范围 定义为以炸弹为圆心的一个圆。

炸弹用一个下标从 0 开始的二维整数数组 bombs 表示，其中 bombs[i] = [xi, yi, ri] 。xi 和 yi 表示第 i 个炸弹的 X 和 Y 坐标，ri 表示爆炸范围的 半径 。

你需要选择引爆 一个 炸弹。当这个炸弹被引爆时，所有 在它爆炸范围内的炸弹都会被引爆，这些炸弹会进一步将它们爆炸范围内的其他炸弹引爆。

给你数组 bombs ，请你返回在引爆 一个 炸弹的前提下，最多 能引爆的炸弹数目。
*/

class Solution {
public:
	int maximumDetonation(vector<vector<int>>& bombs) {
		vector<int> father;
		int n = bombs.size();
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			int now = 0;
			int x = bombs[i][0];
			int y = bombs[i][1];
			int r = bombs[i][2];
			for (int j = 0; j < n; ++j) {
				if (i == j) {
					continue;
				}
				int jx = bombs[j][0];
				int jy = bombs[j][1];
				if (r >= sqrt(double(jx - x) * double(jx - x) + double(jy - y) * double(jy - y))) {
					++now;
				}
			}
			father.push_back(now);
			ans = max(ans, now);
		}
		for (int i = 0; i < n; ++i) {
			int now = 0;
			int x = bombs[i][0];
			int y = bombs[i][1];
			int r = bombs[i][2];
			for (int j = 0; j < n; ++j) {
				if (i == j) {
					continue;
				}
				int jx = bombs[j][0];
				int jy = bombs[j][1];
				if (r >= sqrt(double(jx - x) * double(jx - x) + double(jy - y) * double(jy - y))) {
					now += father[j];
				}
			}
			ans = max(ans, now);
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}