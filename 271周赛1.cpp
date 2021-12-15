#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
总计有 n 个环，环的颜色可以是红、绿、蓝中的一种。这些环分布穿在 10 根编号为 0 到 9 的杆上。

给你一个长度为 2n 的字符串 rings ，表示这 n 个环在杆上的分布。rings 中每两个字符形成一个 颜色位置对 ，用于描述每个环：

第 i 对中的 第一个 字符表示第 i 个环的 颜色（'R'、'G'、'B'）。
第 i 对中的 第二个 字符表示第 i 个环的 位置，也就是位于哪根杆上（'0' 到 '9'）。
例如，"R3G2B1" 表示：共有 n == 3 个环，红色的环在编号为 3 的杆上，绿色的环在编号为 2 的杆上，蓝色的环在编号为 1 的杆上。

找出所有集齐 全部三种颜色 环的杆，并返回这种杆的数量。
*/

class Solution {
public:
	int countPoints(string rings) {
		unordered_map<char, vector<int>> map;
		int n = rings.size();
		int ans = 0;
		for (int i = 0; i < n / 2; ++i) {
			if (map.find(rings[i * 2 + 1]) == map.end()) {
				vector<int> mid(3, 0);
				map[rings[i * 2 + 1]] = mid;
				if (rings[i * 2] == 'B') {
					++map[rings[i * 2 + 1]][0];
				}
				if (rings[i * 2] == 'G') {
					++map[rings[i * 2 + 1]][1];
				}
				if (rings[i * 2] == 'R') {
					++map[rings[i * 2 + 1]][2];
				}
			}
			else {
				if (rings[i * 2] == 'B') {
					++map[rings[i * 2 + 1]][0];
				}
				if (rings[i * 2] == 'G') {
					++map[rings[i * 2 + 1]][1];
				}
				if (rings[i * 2] == 'R') {
					++map[rings[i * 2 + 1]][2];
				}
			}
		}
		unordered_map<char, vector<int>>::iterator it;
		it = map.begin();
		while (it != map.end()) {
			vector<int> col = it->second;
			if (col[0] != 0 && col[1] != 0 && col[2] != 0) {
				++ans;
			}
			++it;
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}