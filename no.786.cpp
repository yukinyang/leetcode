#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>

using namespace std;

/*
给你一个按递增顺序排序的数组 arr 和一个整数 k 。数组 arr 由 1 和若干 素数  组成，且其中所有整数互不相同。

对于每对满足 0 < i < j < arr.length 的 i 和 j ，可以得到分数 arr[i] / arr[j] 。

那么第 k 个最小的分数是多少呢?  以长度为 2 的整数数组返回你的答案, 这里 answer[0] == arr[i] 且 answer[1] == arr[j] 。
*/

class Solution {
public:
	vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
		vector<int> res(2, 0);
		priority_queue<double, vector<double>, greater<double>> fenshu;
		unordered_map<double, vector<int>> map;
		vector<int> mid(2, 0);
		for (int i = 1; i < arr.size(); ++i) {
			fenshu.push(double(arr[0]) / double(arr[i]));
			mid[0] = 0;
			mid[1] = i;
			map[double(arr[0]) / double(arr[i])] = mid;
		}
		vector<int> now;
		for (int i = 0; i < k; ++i) {
			//cout << fenshu.top() << endl;
			now = map[fenshu.top()];
			//cout << now[0] << ' ' << now[1] << endl;
			fenshu.pop();
			if (now[1] > (now[0] + 1)) {
				//cout << 1111 << endl;
				fenshu.push(double(arr[now[0] + 1]) / double(arr[now[1]]));
				mid[0] = now[0] + 1;
				mid[1] = now[1];
				map[double(arr[now[0] + 1]) / double(arr[now[1]])] = mid;
			}
			else {
				continue;
			}
		}
		res[0] = arr[now[0]];
		res[1] = arr[now[1]];
		return res;
	}
};

int main() {
	Solution s;
	vector<int> arr = { 1, 2, 3, 5 };
	vector<int> res = s.kthSmallestPrimeFraction(arr, 3);
	for (int a : res) {
		cout << a << endl;
	}
	system("pause");
	return 0;
}