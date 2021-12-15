#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
给你一个整数 n ，表示网络上的用户数目。每个用户按从 0 到 n - 1 进行编号。

给你一个下标从 0 开始的二维整数数组 restrictions ，其中 restrictions[i] = [xi, yi] 意味着用户 xi 和用户 yi 不能 成为 朋友 ，不管是 直接 还是通过其他用户 间接 。

最初，用户里没有人是其他用户的朋友。给你一个下标从 0 开始的二维整数数组 requests 表示好友请求的列表，其中 requests[j] = [uj, vj] 是用户 uj 和用户 vj 之间的一条好友请求。

如果 uj 和 vj 可以成为 朋友 ，那么好友请求将会 成功 。每个好友请求都会按列表中给出的顺序进行处理（即，requests[j] 会在 requests[j + 1] 前）。

一旦请求成功，那么对所有未来的好友请求而言， uj 和 vj 将会 成为直接朋友 。

返回一个 布尔数组 result ，其中元素遵循此规则：如果第 j 个好友请求 成功 ，那么 result[j] 就是 true ；否则，为 false 。

注意：如果 uj 和 vj 已经是直接朋友，那么他们之间的请求将仍然 成功 。
*/

class Solution {
	int f[1005];
	int get(int x)
	{
		return f[x] = f[x] == x ? x : get(f[x]);
	}
public:
	vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
		int i, j;
		bool b;
		for (i = 0;i<n;i++)f[i] = i;
		vector<bool> ans;
		for (auto &q : requests)
		{
			i = get(q[0]);
			j = get(q[1]);
			if (i == j)
			{
				ans.push_back(1);
				continue;
			}
			b = 1;
			for (auto &e : restrictions)if (get(e[0]) == i && get(e[1]) == j || get(e[1]) == i && get(e[0]) == j)
			{
				b = 0;
				break;
			}
			ans.push_back(b);
			if (b)f[i] = j;
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}