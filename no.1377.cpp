#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

/*
����һ���� n ��������ɵ��������������Ŵ� 1 �� n�����ܴ� ���� 1 ��ʼ�������������£�

��һ���ڣ����ܴ������ڵĵ�ǰ����������һ�� δ���� ���Ķ��㣨�������ֱ����������
�����޷������Ѿ����ʹ��Ķ��㡣
������ܿ������������ͬ���㣬��ô��������������һ�������ϵĻ��ʶ���ͬ��
������ܲ��������κ�δ���ʹ��Ķ����ϣ���ô��ÿ����Ծ����ͣ����ԭ�ء�
�������ı������� edges ���������� edges[i] = [fromi, toi] ��ζ�Ŵ���һ��ֱ����ͨ fromi �� toi ��������ıߡ�

���������� t ���λ��Ŀ�궥�� target �ϵĸ��ʡ�
*/

class Solution {
public:
	vector<int> realroute;
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		vector<vector<int>> tree;
		for (int i = 0; i < edges.size(); ++i) {
			int from = edges[i][0];
			int to = edges[i][1];
		}
	}
};

int main() {
	Solution s;
	vector<vector<int>> edges;
	s.frogPosition(1, edges, 1, 2);
	system("pause");
	return 0;
}