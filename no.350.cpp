#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。

返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。
*/

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;
		unordered_map<int, int> map1;
		for (int num : nums1) {
			if (map1.find(num) == map1.end()) {
				map1[num] = 1;
			}
			else {
				++map1[num];
			}
		}
		for (int num : nums2) {
			if (map1.find(num) != map1.end() && map1[num] > 0) {
				ans.push_back(num);
				--map1[num];
			}
		}
		return ans;
	}
};