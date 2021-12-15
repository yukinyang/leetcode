#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

/*
����һ������Ϊ n ���������� score ������ score[i] �ǵ� i λ�˶�Ա�ڱ����еĵ÷֡����е÷ֶ� ������ͬ ��

�˶�Ա�����ݵ÷� �������� ���������ε� 1 ���˶�Ա�÷���ߣ����ε� 2 ���˶�Ա�÷ֵ� 2 �ߣ��������ơ��˶�Ա�����ξ��������ǵĻ������

���ε� 1 ���˶�Ա����� "Gold Medal" ��
���ε� 2 ���˶�Ա������ "Silver Medal" ��
���ε� 3 ���˶�Ա��ͭ�� "Bronze Medal" ��
�����ε� 4 ���� n ���˶�Ա��ֻ�ܻ�����ǵ����α�ţ��������ε� x ���˶�Ա��ñ�� "x"����
ʹ�ó���Ϊ n ������ answer ���ػ񽱣����� answer[i] �ǵ� i λ�˶�Ա�Ļ������
*/

class Solution {
public:
	vector<string> findRelativeRanks(vector<int>& score) {
		vector<int> mid = score;
		vector<string> ans;
		sort(mid.begin(), mid.end());
		unordered_map<int, string> map;
		for (int i = 0; i < score.size(); ++i) {
			map[mid[i]] = to_string(score.size() -  i);
		}
		for (int i = 0; i < score.size(); ++i) {
			if (score[i] == mid[score.size() - 1]) {
				ans.push_back("Gold Medal");
			}
			else if (score.size() > 1 && score[i] == mid[score.size() - 2]) {
				ans.push_back("Silver Medal");
			}
			else if (score.size() > 2 && score[i] == mid[score.size() - 3]) {
				ans.push_back("Bronze Medal");
			}
			else {
				ans.push_back(map[score[i]]);
			}
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}