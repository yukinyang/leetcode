﻿#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器。
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		int res = 0;
		int left = 0, right = height.size() - 1;
		while (left < right) {
			int now;
			now = (right - left) * min(height[left], height[right]);
			res = max(res, now);
			if (height[left] > height[right]) {
				right--;
				continue;
			}
			else {
				left++;
				continue;
			}
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}