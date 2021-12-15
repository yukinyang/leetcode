#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
给你一个整数数组 arr 和一个整数 difference，请你找出并返回 arr 中最长等差子序列的长度，该子序列中相邻元素之间的差等于 difference 。

子序列 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 arr 派生出来的序列。
*/

class Solution {
public:
	int longestSubsequence(vector<int>& arr, int difference) {
		int res = 0;
		unordered_map<int, int> dif_list;
		if (arr.size() == 0) {
			return 0;
		}
		for (int i = 0; i < arr.size(); ++i) {
			if (dif_list.find(arr[i] - difference) == dif_list.end()) {
				dif_list[arr[i]] = 1;
				res = max(res, 1);
			}
			else if(dif_list.find(arr[i] - difference) != dif_list.end()) {
				dif_list[arr[i]] = dif_list[arr[i] - difference] + 1;
				//if (difference == 0) {
				//	dif_list[arr[i] - difference] = 0;
				//}
				res = max(res, dif_list[arr[i]]);
			}
		}
		return res;
	}
};

int main() {
	vector<int> input = { 4,8,8 };
	Solution s;
	int res = s.longestSubsequence(input, 0);
	cout << res << endl;
	system("pause");
	return 0;
}