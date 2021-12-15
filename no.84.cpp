#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

/*
���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 ��

���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
*/

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		/* ���������Եĳ�ʱ */
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

		/* ����ջ��� */
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