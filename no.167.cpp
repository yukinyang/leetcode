#include <iostream>
#include <vector>

using namespace std;

/*
给定一个已按照 非递减顺序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。

函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		vector<int> ans(2, 0);
		ans[0] = 0;
		ans[1] = numbers.size() - 1;
		while (numbers[ans[0]] + numbers[ans[1]] != target) {
			if (numbers[ans[0]] + numbers[ans[1]] > target) {
				--ans[1];
			}
			else {
				++ans[0];
			}
		}
		++ans[0];
		++ans[1];
		return ans;
	}
};