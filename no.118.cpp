#include <iostream>
#include <vector>

using namespace std;

/*
����һ���Ǹ����� numRows�����ɡ�������ǡ���ǰ numRows �С�

�ڡ�������ǡ��У�ÿ�����������Ϸ������Ϸ������ĺ͡�
*/

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> ans;
		vector<int> last = { 1 };
		ans.push_back(last);
		vector<int> mid;
		for (int i = 1; i < numRows; ++i) {
			mid.resize(i + 1, 1);
			for (int j = 1; j < mid.size() - 1; ++j) {
				mid[j] = last[j - 1] + last[j + 1];
			}
			ans.push_back(mid);
			last = mid;
		}
		return ans;
	}
};