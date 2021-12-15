#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/

/*
因为长度较长，所以dfs肯定会超时，所以不考虑dfs

重写双（三）指针
*/

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		/* 原来的写法 */
		//vector<vector<int>> res;
		//vector<int> now;
		//sort(nums.begin(), nums.end());
		//for (int i = 0; i < nums.size(); ++i) {
		//	if (nums[i] > 0) {
		//		break;
		//	}
		//	if (i > 0 && nums[i] == nums[i - 1]) {
		//		continue;
		//	}
		//	int left = i + 1, right = nums.size() - 1;
		//	now.push_back(nums[i]);
		//	while (left < right) {
		//		//if (left == i) {
		//		//	++left;
		//		//	continue;
		//		//}
		//		//if (right == i) {
		//		//	--right;
		//		//	continue;
		//		//}
		//		if ((nums[left] + nums[right]) == (0 - nums[i])) {
		//			now.push_back(nums[left]);
		//			now.push_back(nums[right]);
		//			if (res.size() == 0) {
		//				res.push_back(now);
		//			}
		//			if (res.size() > 0 && now != res[res.size() - 1]) {
		//				res.push_back(now);
		//			}
		//			now.pop_back();
		//			now.pop_back();
		//			++left;
		//		}
		//		else if ((nums[left] + nums[right]) > (0 - nums[i])) {
		//			--right;
		//		}
		//		else {
		//			++left;
		//		}
		//	}
		//	now.pop_back();
		//}
		//return res;

		/* 重写双（三）指针 */
		vector<vector<int>> ans;
		if (nums.size() == 0) {
			return ans;
		}
		int a, b, c;
		sort(nums.begin(), nums.end());
		for (int a = 0; a < int(nums.size()) - 2; ++a) {
			if (a > 0 && nums[a] == nums[a - 1]) {
				continue;
			}
			b = a + 1;
			c = nums.size() - 1;
			while (b < c) {
				if (b > a + 1 && nums[b] == nums[b - 1]) {
					++b;
					continue;
				}
				if (c < nums.size() - 1 && nums[c] == nums[c + 1]) {
					--c;
					continue;
				}
				if (nums[a] + nums[b] + nums[c] == 0) {
					ans.push_back({ nums[a], nums[b], nums[c] });
					++b;
					--c;
				}
				else if (nums[a] + nums[b] + nums[c] < 0) {
					++b;
				}
				else {
					--c;
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<int> test = { -4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6 };
	vector<vector<int>> res = s.threeSum(test);
	for (vector<int> re : res) {
		for (int r : re) {
			cout << r << ' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}