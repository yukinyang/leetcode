#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;	

/*
	给你两个 没有重复元素 的数组 nums1 和 nums2 ，其中nums1 是 nums2 的子集。

	请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。

	nums1 中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 - 1 。

	一但要求下一个更大的元素，就是用单调栈解
*/

class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res(0, 0);
		for (int i = 0; i < nums1.size(); i++) {
			int now = nums1[i];
			bool getnow = false;
			bool getbigger = false;
			for (int j = 0; j < nums2.size(); j++) {
				if (nums2[j] == now) {
					getnow = true;
					continue;
				}
				if (getnow && nums2[j] > now) {
					getbigger = true;
					res.push_back(nums2[j]);
					break;
				}
			}
			if (!getbigger) {
				res.push_back(-1);
			}
		}
		return res;
	}
	vector<int> nextGreaterElement_hash(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res(0, 0);
		unordered_map<int, int> right_bigger;
		stack<int> mid;
		mid.push(nums2[nums2.size() - 1]);
		for (int i = nums2.size() - 1; i >= 0; i--) {
			if (nums2[i] < mid.top()) {
				right_bigger[nums2[i]] = mid.top();
			}
			else {
				while(! mid.empty() && nums2[i] >= mid.top()){
					mid.pop();
				}
				if (mid.empty()) {
					mid.push(nums2[i]);
					right_bigger[nums2[i]] = -1;
				}
				else {
					right_bigger[nums2[i]] = mid.top();
				}
			}
			mid.push(nums2[i]);
		}
		for (int i = 0; i < nums1.size(); i++) {
			res.push_back(right_bigger[nums1[i]]);
		}
		return res;
	}
};

int main() {
	int a[3] = { 4, 1, 2 };
	int b[4] = { 1, 3, 4, 2 };
	vector<int> nums1(a, a + 3);
	vector<int> nums2(b, b + 4);
	Solution s;
	vector<int> res;
	res = s.nextGreaterElement_hash(nums1, nums2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << ' ';
	}
	system("pause");
	return 0;
}