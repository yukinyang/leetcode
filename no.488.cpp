#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
�����ڲ���������Ϸ��һ�����֡�

�����������Ϸ�����У��������� һ�� ����ÿ�������ɫ�����ǣ���ɫ 'R'����ɫ 'Y'����ɫ 'B'����ɫ 'G' ���ɫ 'W' ���������Ҳ��һЩ����

���Ŀ���� ��� ���������е���ÿһ�غϣ�

�������ϵĲ�����ѡ�� ����һ�� ��Ȼ���������������һ�����У�����֮�����һ�������һ�ˡ�
���ţ�����г��� ���������������� �� ��ɫ��ͬ ���������Ļ����Ͱ������Ƴ�����
��������Ƴ�����ͬ�����³�����������������������ɫ��ͬ��������������Լ����Ƴ���Щ��ֱ�����������Ƴ�������
��������������򶼱��Ƴ�������Ϊ��Ӯ�ñ�����Ϸ��
�ظ�������̣�ֱ����Ӯ����Ϸ��������û�и������
����һ���ַ��� board ����ʾ�������ʼ�������������һ���ַ��� hand ����ʾ����Ĳ���
���㰴�������������Ƴ������������򣬼��㲢���������������������������Ƴ��������е��򣬷��� -1 ��
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