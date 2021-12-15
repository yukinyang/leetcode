#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
����һ���������飬�ж��Ƿ�����ظ�Ԫ�ء�

�������һֵ�������г����������Σ��������� true �����������ÿ��Ԫ�ض�����ͬ���򷵻� false ��
*/

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> times;
		for (int num : nums) {
			if (times.find(num) != times.end()) {
				return true;
			}
			times[num] = 1;
		}
		return false;
	}
};
