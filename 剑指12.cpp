#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。
*/

class Solution {
public:
	string mid = "";
	bool exist(vector<vector<char>>& board, string word) {
		vector<vector<int>> used(board.size(), vector<int>(board[0].size(), 0));
		vector<int> start = { 0, 0 };
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[0].size(); ++j) {
				char now = board[i][j];
				if (now == word[0]) {
					//cout << "****************************" << endl;
					mid.clear();
					if (get(board, used, word, i, j, word)) {
						return true;
					}
				}
			}
		}
		return false;
	}

	bool get(vector<vector<char>>& board, vector<vector<int>>& used, string word, int h, int w, string reword){
		used[h][w] = 1;
		mid.push_back(board[h][w]);
		//cout << "( " << h << ", " << w << " )" << endl;
		//cout << mid << endl;
		if (mid.size() == reword.size()) {
			if (mid == reword) {
				return true;
			}
			else{
				return false;
			}
		}
		bool res = false;
		if (h > 0 && used[h - 1][w] != 1 && board[h - 1][w] == word[1]) {
			string newword(word, 1);
			//res = res || get(board, used, newword, h - 1, w, reword);
			//used[h - 1][w] = 0;
			if (get(board, used, newword, h - 1, w, reword)) {
				return true;
			}
			mid.pop_back();
		}
		if (h < board.size() - 1 && used[h + 1][w] != 1 && board[h + 1][w] == word[1]) {
			string newword(word, 1);
			//res = res || get(board, used, newword, h + 1, w, reword);
			//used[h + 1][w] = 0;
			if (get(board, used, newword, h + 1, w, reword)) {
				return true;
			}
			mid.pop_back();
		}
		if (w < board[0].size() - 1 && used[h][w + 1] != 1 && board[h][w + 1] == word[1]) {
			string newword(word, 1);
			//res = res || get(board, used, newword, h, w + 1, reword);
			//used[h][w + 1] = 0;
			if (get(board, used, newword, h, w + 1, reword)) {
				return true;
			}
			mid.pop_back();
		}
		if (w > 0 && used[h][w - 1] != 1 && board[h][w - 1] == word[1]) {
			string newword(word, 1);
			//res = res || get(board, used, newword, h, w - 1, reword);
			//used[h][w - 1] = 0;
			if (get(board, used, newword, h, w - 1, reword)) {
				return true;
			}
			mid.pop_back();
		}
		used[h][w] = 0;
		return false;
	}

	bool string_eq(string a, string b) {
		return false;
	}
};

int main() {
	Solution s;
	vector<vector<char>> board = {{'C','C','C','C'}, {'C','C','C','C' }, { 'C','C','C','C'}};
	string word = "CCCCCCCCCC";
	bool res = s.exist(board, word);
	cout << boolalpha << res << endl;
	system("pause");
	return 0;
}