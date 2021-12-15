#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
给你一个整数 n ，表示有 n 个专家从 0 到 n - 1 编号。

另外给你一个下标从 0 开始的二维整数数组 meetings ，其中 meetings[i] = [xi, yi, timei] 表示专家 xi 和专家 yi 在时间 timei 要开一场会。

一个专家可以同时参加 多场会议 。最后，给你一个整数 firstPerson 。

专家 0 有一个 秘密 ，最初，他在时间 0 将这个秘密分享给了专家 firstPerson 。

接着，这个秘密会在每次有知晓这个秘密的专家参加会议时进行传播。

更正式的表达是，每次会议，如果专家 xi 在时间 timei 时知晓这个秘密，那么他将会与专家 yi 分享这个秘密，反之亦然。

秘密共享是 瞬时发生 的。也就是说，在同一时间，一个专家不光可以接收到秘密，还能在其他会议上与其他专家分享。

在所有会议都结束之后，返回所有知晓这个秘密的专家列表。你可以按 任何顺序 返回答案。
*/

class Solution {
public:
	vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
		vector<int> res = { firstPerson };
		unordered_map<vector<int>, int> map;
		int maxtime = 0;
		for (int i = 0; i < meetings.size(); ++i) {
			map[meetings[i]] = 1;
			maxtime = max(maxtime, meetings[i][2]);
		}
		for (int i = 1; i < maxtime; ++i) {
			for()
		}
	}
};

int main() {
	system("pause");
	return 0;
}