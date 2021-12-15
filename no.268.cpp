#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

*/

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int res = 0;
		sort(nums.begin(), nums.end());
		if (nums[0] != 0) {
			return 0;
		}
		if (nums[nums.size() - 1] != nums.size()) {
			return nums.size();
		}
		/* ±éÀú */
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] - nums[i - 1] == 2) {
				return nums[i] - 1;
			}
		}
		/* ¶þ·Ö */
		int left = 0, right = nums.size() - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			if ((nums[mid] - nums[left]) == (mid - left)) {
				left = mid + 1;
				res = left;
			}
			else {
				right = mid - 1;
				res = right + 1;
			}
		}
		return res;
	}
};

int main() {
	system("pause");
	return 0;
}