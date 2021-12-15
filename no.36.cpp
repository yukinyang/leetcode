﻿#include <iostream>
#include <vector>

using namespace std;

/*
请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 

 注意：

 一个有效的数独（部分已被填充）不一定是可解的。
 只需要根据以上规则，验证已经填入的数字是否有效即可。
 空白格用 '.' 表示。
*/

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int h = 9, w = 9;
		for (vector<char> hang : board) {
			vector<int> nums(9, 0);
			for (char ch : hang) {
				if (ch != '.') {
					++nums[ch - '1'];
					if (nums[ch - '1'] > 1) {
						return false;
					}
				}
			}
		}
		for (int i = 0; i < w; ++i) {
			vector<int> nums(9, 0);
			for (int j = 0; j < h; ++j) {
				if (board[j][i] != '.') {
					++nums[board[j][i] - '1'];
					if (nums[board[j][i] - '1'] > 1) {
						return false;
					}
				}
				// if(i == 3)cout << nums[6] << endl;
			}
			 //for (int xx : nums) {
			 //	cout << xx << ' ';
			 //}
			 //cout << endl;
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				int x = i * 3, y = j * 3;
				vector<int> nums(9, 0);
				for (int a = x; a < x + 3; ++a) {
					for (int b = y; b < y + 3; ++b) {
						if (board[a][b] != '.') {
							++nums[board[a][b] - '1'];
							if (nums[board[a][b] - '1'] > 1) {
								return false;
							}
						}
					}
				}
			}
		}
		return true;
	}
};