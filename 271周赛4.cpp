#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
在一个无限的 x 坐标轴上，有许多水果分布在其中某些位置。给你一个二维整数数组 fruits ，其中 fruits[i] = [positioni, amounti] 表示共有 amounti 个水果放置在 positioni 上。fruits 已经按 positioni 升序排列 ，每个 positioni 互不相同 。

另给你两个整数 startPos 和 k 。最初，你位于 startPos 。从任何位置，你可以选择 向左或者向右 走。在 x 轴上每移动 一个单位 ，就记作 一步 。你总共可以走 最多 k 步。你每达到一个位置，都会摘掉全部的水果，水果也将从该位置消失（不会再生）。

返回你可以摘到水果的 最大总数 。
*/

class Solution {
public:
	int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
		int ans = 0;
		int n = fruits.size();
		int l = startPos - k;
		int r = startPos + k;
		unordered_map<int, int> map;
		for (int i = 0; i < n; ++i) {
			//if(fruits[i][0] >= l && fruits[i][0] <= r)
			map[fruits[i][0]] = fruits[i][1];
		}
		vector<int> midl(k + 1, 0);
		vector<int> midr(k + 1, 0);
		int all_l = 0, all_r = 0;
		for (int i = 1; i < k + 1; ++i) {
			if (map.find(startPos - i) != map.end()) {
				all_l += map[startPos - i];
			}
			midl[i] = all_l;
			if (map.find(startPos + i) != map.end()) {
				all_r += map[startPos + i];
			}
			midr[i] = all_r;
		}
		for (int i = 0; i < k + 1; ++i) {
			int len_l = i;
			int len_r = k - i * 2;
			if (len_r < 0) {
				len_r = 0;
			}
			ans = max(ans, midl[len_l] + midr[len_r]);
		}
		for (int i = 0; i < k + 1; ++i) {
			int len_r = i;
			int len_l = k - i * 2;
			if (len_l < 0) {
				len_l = 0;
			}
			ans = max(ans, midl[len_l] + midr[len_r]);
		}
		if (map.find(startPos) != map.end()) {
			ans += map[startPos];
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}