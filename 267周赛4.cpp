#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
����һ������ n ����ʾ�����ϵ��û���Ŀ��ÿ���û����� 0 �� n - 1 ���б�š�

����һ���±�� 0 ��ʼ�Ķ�ά�������� restrictions ������ restrictions[i] = [xi, yi] ��ζ���û� xi ���û� yi ���� ��Ϊ ���� �������� ֱ�� ����ͨ�������û� ��� ��

������û���û�����������û������ѡ�����һ���±�� 0 ��ʼ�Ķ�ά�������� requests ��ʾ����������б����� requests[j] = [uj, vj] ���û� uj ���û� vj ֮���һ����������

��� uj �� vj ���Գ�Ϊ ���� ����ô�������󽫻� �ɹ� ��ÿ���������󶼻ᰴ�б��и�����˳����д�������requests[j] ���� requests[j + 1] ǰ����

һ������ɹ�����ô������δ���ĺ���������ԣ� uj �� vj ���� ��Ϊֱ������ ��

����һ�� �������� result ������Ԫ����ѭ�˹�������� j ���������� �ɹ� ����ô result[j] ���� true ������Ϊ false ��

ע�⣺��� uj �� vj �Ѿ���ֱ�����ѣ���ô����֮���������Ȼ �ɹ� ��
*/

class Solution {
	int f[1005];
	int get(int x)
	{
		return f[x] = f[x] == x ? x : get(f[x]);
	}
public:
	vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
		int i, j;
		bool b;
		for (i = 0;i<n;i++)f[i] = i;
		vector<bool> ans;
		for (auto &q : requests)
		{
			i = get(q[0]);
			j = get(q[1]);
			if (i == j)
			{
				ans.push_back(1);
				continue;
			}
			b = 1;
			for (auto &e : restrictions)if (get(e[0]) == i && get(e[1]) == j || get(e[1]) == i && get(e[0]) == j)
			{
				b = 0;
				break;
			}
			ans.push_back(b);
			if (b)f[i] = j;
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}