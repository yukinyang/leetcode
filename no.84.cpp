#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		/* 暴力，绝对的超时 */
		//int ans = 0;
		//for (int i = 0; i < heights.size(); ++i) {
		//	int l = i, r = i;
		//	while (l >= 0 && heights[l] >= heights[i]) {
		//		--l;
		//	}
		//	while (r < heights.size() && heights[r] >= heights[i]) {
		//		++r;
		//	}
		//	ans = max(ans, (r - l) * heights[i]);
		//}
		//return ans;

		/* 辅助栈求解 */
		stack<int> stk;
		int ans = 0;
		heights.insert(heights.begin(), 0);
		heights.push_back(0);
		//for (int i : heights) {
		//	cout << i << ' ';
		//}
		//cout << endl;
		stk.push(0);
		for (int i = 1; i < heights.size(); ++i) {
			while (stk.size() && heights[stk.top()] > heights[i]) {
				int now_height = heights[stk.top()];
				stk.pop();
				ans = max(ans, (i - stk.top() - 1) * now_height);
			}
			stk.push(i);
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> heights = { 2,1,5,6,2,3 };
	int ans = s.largestRectangleArea(heights);
	cout << ans << endl;
	system("pause");
	return 0;
}