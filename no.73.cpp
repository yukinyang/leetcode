#include <iostream>
#include <vector>

using namespace std;

/*
����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ�� ԭ�� �㷨��
*/

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int h = matrix.size(), w = matrix[0].size();
		bool hang0 = false, lie0 = false;
		for (int i = 0; i < w; ++i) {
			if (matrix[0][i] == 0) {
				hang0 = true;
			}
		}
		for (int i = 0; i < h; ++i) {
			if (matrix[i][0] == 0) {
				lie0 = true;
			}
		}
		for (int i = 1; i < h; ++i) {
			for (int j = 1; j < w; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = 0;
					matrix[0][j] = 0;
				}
			}
		}
		for (int i = 1; i < w; ++i) {
			if (matrix[0][i] == 0) {
				for (int j = 0; j < h; ++j) {
					matrix[j][i] = 0;
				}
			}
		}
		for (int i = 1; i < h; ++i) {
			if (matrix[i][0] == 0) {
				for (int j = 0; j < w; ++j) {
					matrix[i][j] = 0;
				}
			}
		}
		if (hang0) {
			for (int i = 0; i < w; ++i) {
				matrix[0][i] = 0;
			}
		}
		if (lie0) {
			for (int i = 0; i < h; ++i) {
				matrix[i][0] = 0;
			}
		}
	}
};