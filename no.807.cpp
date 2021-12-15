#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
�ڶ�ά����grid�У�grid[i][j]����λ��ĳ���Ľ�����ĸ߶ȡ� ���Ǳ����������κ���������ͬ��������������ܲ�ͬ���Ľ�����ĸ߶ȡ� �߶� 0 Ҳ����Ϊ�ǽ����

��󣬴�������������ĸ����򣨼��������ײ��������Ҳࣩ�ۿ��ġ�����ߡ�������ԭʼ������������ͬ�� 
���е�������Ǵ�Զ���ۿ�ʱ�������н������γɵľ��ε��ⲿ������ �뿴��������ӡ�

������߶ȿ������ӵ�����ܺ��Ƕ��٣�
*/

class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		int ans = 0;
		int h = grid.size(), w = grid[0].size();
		vector<int> h_max(h, 0), w_max(w, 0);
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				w_max[j] = max(w_max[j], grid[i][j]);
				h_max[i] = max(h_max[i], grid[i][j]);
			}
		}
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				ans += (min(w_max[j], h_max[i]) - grid[i][j]);
			}
		}
		return ans;
	}
};