#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ���������� nums �������ҳ�һ���������͵����������飨���������ٰ���һ��Ԫ�أ������������͡�

������ �������е�һ���������֡�
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size(), 0);
		dp[0] = nums[0];
		int ans = dp[0];
		for (int i = 1; i < nums.size(); ++i) {
			dp[i] = max(nums[i], nums[i] + dp[i - 1]);
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}