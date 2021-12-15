#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ���±�� 0 ��ʼ������ nums ������������ ������ͬ ��������ɡ�

nums ����һ��ֵ��С��Ԫ�غ�һ��ֵ����Ԫ�ء��ֱ��Ϊ ��Сֵ �� ���ֵ �����Ŀ���Ǵ��������Ƴ�������Ԫ�ء�

һ�� ɾ�� ��������Ϊ������� ǰ�� �Ƴ�һ��Ԫ�ػ������� ���� �Ƴ�һ��Ԫ�ء�

���ؽ���������Сֵ�����ֵ �� �Ƴ���Ҫ����Сɾ��������
*/

class Solution {
public:
	int minimumDeletions(vector<int>& nums) {
		vector<int> mid = nums;
		sort(mid.begin(), mid.end());
		int xiao, da;
		bool getx = false, getd = false;
		for (int i = 0; i < nums.size(); ++i) {
			if (mid[0] == nums[i]) {
				xiao = i;
				getx = true;
			}
			if (mid[nums.size() - 1] == nums[i]) {
				da = i;
				getd = true;
			}
			if (getd && getx) {
				break;
			}
		}
		int a, b, c;
		a = max(xiao, da) +1;
		b = nums.size() - min(xiao, da) + 1;
		c = nums.size() - max(xiao, da) + 1 + min(xiao, da) + 1;
		return min(a, min(b, c));
	}
};

int main() {
	system("pause");
	return 0;
}