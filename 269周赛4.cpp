#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
����һ������ n ����ʾ�� n ��ר�Ҵ� 0 �� n - 1 ��š�

�������һ���±�� 0 ��ʼ�Ķ�ά�������� meetings ������ meetings[i] = [xi, yi, timei] ��ʾר�� xi ��ר�� yi ��ʱ�� timei Ҫ��һ���ᡣ

һ��ר�ҿ���ͬʱ�μ� �ೡ���� ����󣬸���һ������ firstPerson ��

ר�� 0 ��һ�� ���� �����������ʱ�� 0 ��������ܷ������ר�� firstPerson ��

���ţ�������ܻ���ÿ����֪��������ܵ�ר�Ҳμӻ���ʱ���д�����

����ʽ�ı���ǣ�ÿ�λ��飬���ר�� xi ��ʱ�� timei ʱ֪��������ܣ���ô��������ר�� yi ����������ܣ���֮��Ȼ��

���ܹ����� ˲ʱ���� �ġ�Ҳ����˵����ͬһʱ�䣬һ��ר�Ҳ�����Խ��յ����ܣ�����������������������ר�ҷ���

�����л��鶼����֮�󣬷�������֪��������ܵ�ר���б�����԰� �κ�˳�� ���ش𰸡�
*/

class Solution {
public:
	vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
		vector<int> res = { firstPerson };
		unordered_map<vector<int>, int> map;
		int maxtime = 0;
		for (int i = 0; i < meetings.size(); ++i) {
			map[meetings[i]] = 1;
			maxtime = max(maxtime, meetings[i][2]);
		}
		for (int i = 1; i < maxtime; ++i) {
			for()
		}
	}
};

int main() {
	system("pause");
	return 0;
}