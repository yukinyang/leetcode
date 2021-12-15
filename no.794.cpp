#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
给你一个字符串数组 board 表示井字游戏的棋盘。当且仅当在井字游戏过程中，棋盘有可能达到 board 所显示的状态时，才返回 true 。

井字游戏的棋盘是一个 3 x 3 数组，由字符 ' '，'X' 和 'O' 组成。字符 ' ' 代表一个空位。

以下是井字游戏的规则：

玩家轮流将字符放入空位（' '）中。
玩家 1 总是放字符 'X' ，而玩家 2 总是放字符 'O' 。
'X' 和 'O' 只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。
*/

class Solution {
public:
	bool validTicTacToe(vector<string>& board) {
		int numx = 0, numo = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				if (board[i][j] == 'X') {
					++numx;
				}
				if (board[i][j] == 'O') {
					++numo;
				}
			}
		}
		if (!(numx == numo || numx - numo == 1)) {
			return false;
		}
		vector<int> mid = num_over(board);
		// cout << num_over(board) << endl;
		if (numx < 5) {
			if (mid[0] == 0) {
				return (numx == numo || numx - numo == 1);
			}
			else if (mid[0] == 1) {
				return mid[1] == 1 ? numx - numo == 1 : numx == numo;
			}
			else {
				return false;
			}
		}
		else {
			return mid[0] <= 2 && mid[2] == 0;
		}
	}

	vector<int> num_over(vector<string>& board) {
		vector<int> ans(3, 0);
		int num = 0, x = 0, o = 0;
		for (int i = 0; i < 3; ++i) {
			if (board[0][i] == board[1][i] && board[2][i] == board[1][i] && board[0][i] != ' ') {
				if (board[0][i] == 'X') {
					++x;
				}
				else {
					++o;
				}
				++num;
			}
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
				if (board[i][0] == 'X') {
					++x;
				}
				else {
					++o;
				}
				++num;
			}
		}
		if (board[1][1] == board[0][0] && board[2][2] == board[0][0] && board[1][1] != ' ') {
			if (board[1][1] == 'X') {
				++x;
			}
			else {
				++o;
			}
			++num;
		}
		if (board[1][1] == board[0][2] && board[1][1] == board[2][0] && board[1][1] != ' ') {
			if (board[1][1] == 'X') {
				++x;
			}
			else {
				++o;
			}
			++num;
		}
		ans[0] = num;
		ans[1] = x;
		ans[2] = o;
		return ans;
	}
};

