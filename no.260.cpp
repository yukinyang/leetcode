#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

 进阶：你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
*/

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		/* hash_map */
		//vector<int> res;
		//unordered_map<int, int> map;
		//for (int i = 0; i < nums.size(); i++) {
		//	if (map.find(nums[i]) == map.end()) {
		//		map[nums[i]] = 1;
		//	}
		//	else {
		//		map[nums[i]] ++;
		//	}
		//}
		//unordered_map<int, int> ::iterator it = map.begin();
		//while (it != map.end()) {
		//	if (it->second == 1) {
		//		res.push_back(it->first);
		//	}
		//	it++;
		//}
		//return res;

		/* 异或 */
		vector<int> res(2, 0);
		int sum;
		for (int i = 0; i < nums.size(); i++) {
			sum ^= nums[i];
		}
		int bit = (sum == INT_MIN ? sum : sum & (-sum));
		for (int i = 0; i < nums.size(); i++) {
			if ((nums[i] & bit) == 0) {
				res[0] ^= nums[i];
			}
			else {
				res[1] ^= nums[i];
			}
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}