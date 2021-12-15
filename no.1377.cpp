#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

/*
给你一棵由 n 个顶点组成的无向树，顶点编号从 1 到 n。青蛙从 顶点 1 开始起跳。规则如下：

在一秒内，青蛙从它所在的当前顶点跳到另一个 未访问 过的顶点（如果它们直接相连）。
青蛙无法跳回已经访问过的顶点。
如果青蛙可以跳到多个不同顶点，那么它跳到其中任意一个顶点上的机率都相同。
如果青蛙不能跳到任何未访问过的顶点上，那么它每次跳跃都会停留在原地。
无向树的边用数组 edges 描述，其中 edges[i] = [fromi, toi] 意味着存在一条直接连通 fromi 和 toi 两个顶点的边。

返回青蛙在 t 秒后位于目标顶点 target 上的概率。
*/

class Solution {
public:
	vector<int> realroute;
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		vector<vector<int>> tree;
		for (int i = 0; i < edges.size(); ++i) {
			int from = edges[i][0];
			int to = edges[i][1];
		}
	}
};

int main() {
	Solution s;
	vector<vector<int>> edges;
	s.frogPosition(1, edges, 1, 2);
	system("pause");
	return 0;
}