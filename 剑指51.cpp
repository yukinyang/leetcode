#include <iostream>
#include <vector>

using namespace std;

/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
*/

class Solution {
public:
	int res = 0;
	int reversePairs(vector<int>& nums) {
		/* 暴力解发，超时 */
		//int res = 0;
		//if (nums.size() <= 1) {
		//	return res;
		//}
		//for (int i = 0; i < nums.size() - 1; ++i) {
		//	for (int j = i + 1; j < nums.size(); ++j) {
		//		if (nums[j] < nums[i]) {
		//			++res;
		//		}
		//	}
		//}
		mergesort(nums);
		return res;
	}

	vector<int> merge(vector<int> left, vector<int> right) {
		vector<int> res_now;
		int l = 0, r = 0;
		while (l < left.size() || r < right.size()) {
			if (r < right.size() && l < left.size() && right[r] < left[l]) {
				res += left.size() - l;
				res_now.push_back(right[r]);
				++r;
			}
			if(l < left.size() && r < right.size()  && right[r] >= left[l]) {
				res_now.push_back(left[l]);
				++l;
			}
			if (r >= right.size() && l < left.size()) {
				res_now.push_back(left[l]);
				++l;
			}
			if (r < right.size() && l >= left.size()) {
				res_now.push_back(right[r]);
				++r;
			}
		}
		return res_now;
	}

	vector<int> mergesort(vector<int> input) {
		if (input.size() < 2) {
			return input;
		}
		int mid = input.size() / 2;
		vector<int> left(input.begin(), input.begin() + mid);
		vector<int> right(input.begin() + mid, input.end());
		return merge(mergesort(left), mergesort(right));
	}
};

int main() {
	vector<int> test = { 4, 5, 6, 7 };
	Solution s;
	vector<int> res = s.mergesort(test);
	for (int a : res) {
		cout << a << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}