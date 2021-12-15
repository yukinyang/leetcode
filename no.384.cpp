#include <iostream>
#include <vector>

using namespace std;

/*
给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。

实现 Solution class:

Solution(int[] nums) 使用整数数组 nums 初始化对象
int[] reset() 重设数组到它的初始状态并返回
int[] shuffle() 返回数组随机打乱后的结果
*/

class Solution {
public:
	vector<int> re;
	vector<int> used;
	Solution(vector<int>& nums) {
		re = nums;
		used.resize(nums.size(), 0);
	}

	vector<int> reset() {
		return re;
	}

	vector<int> shuffle() {
		vector<int> res;
		int now;
		for (int i = 0; i < re.size(); ++i) {
			now = rand() % re.size();
			while (used[now] == 1) {
				now = rand() % re.size();
			}
			used[now] = 1;
			res.push_back(re[now]);
		}
		fill(used.begin(), used.end(), 0);
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}