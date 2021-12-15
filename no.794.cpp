#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
����һ���ַ������� board ��ʾ������Ϸ�����̡����ҽ����ھ�����Ϸ�����У������п��ܴﵽ board ����ʾ��״̬ʱ���ŷ��� true ��

������Ϸ��������һ�� 3 x 3 ���飬���ַ� ' '��'X' �� 'O' ��ɡ��ַ� ' ' ����һ����λ��

�����Ǿ�����Ϸ�Ĺ���

����������ַ������λ��' '���С�
��� 1 ���Ƿ��ַ� 'X' ������� 2 ���Ƿ��ַ� 'O' ��
'X' �� 'O' ֻ��������ڿ�λ�У���������ѷ����ַ���λ�ý�����䡣
���� 3 ����ͬ���ҷǿգ����ַ�����κ��С��л�Խ���ʱ����Ϸ������
������λ�÷ǿ�ʱ��Ҳ��Ϊ��Ϸ������
�����Ϸ��������Ҳ������ٷ����ַ���
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

