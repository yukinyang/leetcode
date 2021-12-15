#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
你正在参与祖玛游戏的一个变种。

在这个祖玛游戏变体中，桌面上有 一排 彩球，每个球的颜色可能是：红色 'R'、黄色 'Y'、蓝色 'B'、绿色 'G' 或白色 'W' 。你的手中也有一些彩球。

你的目标是 清空 桌面上所有的球。每一回合：

从你手上的彩球中选出 任意一颗 ，然后将其插入桌面上那一排球中：两球之间或这一排球的任一端。
接着，如果有出现 三个或者三个以上 且 颜色相同 的球相连的话，就把它们移除掉。
如果这种移除操作同样导致出现三个或者三个以上且颜色相同的球相连，则可以继续移除这些球，直到不再满足移除条件。
如果桌面上所有球都被移除，则认为你赢得本场游戏。
重复这个过程，直到你赢了游戏或者手中没有更多的球。
给你一个字符串 board ，表示桌面上最开始的那排球。另给你一个字符串 hand ，表示手里的彩球。
请你按上述操作步骤移除掉桌上所有球，计算并返回所需的最少球数。如果不能移除桌上所有的球，返回 -1 。
*/

class Solution {
public:
	int leftballs = -1;
	int findMinStep(string board, string hand) {
		int left = hand.size();
		vector<int> used(left, 0);
		int res = shot(board, hand, left, used);
		if (res == -1) {
			return res;
		}
		return left - shot(board, hand, left, used);
	}

	int shot(string board, string hand, int left, vector<int>& used) {
		//cout << board << endl;
		if (left <= leftballs) {
			return leftballs;
		}
		while (board != clear(board)) {
			board = clear(board);
		}
		if (board.size() == 0) {
			//cout << left << endl;
			return left;
		}
		if (left == 0) {
			return -1;
		}
		for (int j = 0; j < used.size(); ++j) {
			if (used[j] == 1) {
				continue;
			}
			char now = hand[j];
			used[j] = 1;
			for (int i = 0; i < board.size(); ++i) {
				board.insert(i, 1, now);
				leftballs = max(leftballs, shot(board, hand, left - 1, used));
				board.erase(i, 1);
			}
			used[j] = 0;
		}
		return leftballs;
	}

	string clear(string input) {
		if (input.size() < 3) {
			return input;
		}
		string res;
		res.push_back(input[0]);
		res.push_back(input[1]);
		for (int i = 2; i < input.size(); ++i) {
			if (input[i] == input[i - 1] && input[i] == input[i - 2]) {
				while (res.size() != 0 && res[res.size() - 1] == input[i]) {
					res.pop_back();
				}
				continue;
			}
			res.push_back(input[i]);
		}
		return res;
	}
};

int main() {
	Solution s;
	string board = "RBYYBBRRB";
	string hand = "YRBGB";
	int res = s.findMinStep(board, hand);
	cout << res << endl;
	system("pause");
	return 0;
}