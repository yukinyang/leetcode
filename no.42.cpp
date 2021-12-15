#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
*/

class Solution {
public:
	int trap(vector<int>& height) {
		int ans = 0;
		vector<int> l(height.size(), 0), r(height.size(), 0);
		for (int i = 1; i < height.size(); ++i) {
			l[i] = max(l[i - 1], height[i - 1]);
			r[height.size() - 1 - i] = max(r[height.size() - i], height[height.size() - i]);
		}
		for (int i = 1; i < height.size() - 1; ++i) {
			ans += min(l[i], r[i]) > height[i] ? min(l[i], r[i]) - height[i] : 0;
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> test = { 2,1,0,1,3,2,1,2,1 };
	int ans = s.trap(test);
	system("pause");
	return 0;
}