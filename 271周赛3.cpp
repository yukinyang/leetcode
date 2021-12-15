#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
Alice �� Bob �������԰��� n ��ֲ�ｽˮ��ֲ���ų�һ�У������ҽ��б�ǣ���Ŵ� 0 �� n - 1 �����У��� i ��ֲ���λ���� x = i ��

ÿһ��ֲ�ﶼ��Ҫ���ض�����ˮ��Alice �� Bob ÿ����һ��ˮ�ޣ���������� �����ǰ����������ķ�ʽ��ɽ�ˮ��

Alice �� ������ ��˳���ֲ�ｽˮ����ֲ�� 0 ��ʼ��Bob �� ���ҵ��� ��˳���ֲ�ｽˮ����ֲ�� n - 1 ��ʼ������ ͬʱ ��ֲ�ｽˮ��
���û���㹻��ˮ ��ȫ ������һ��ֲ��� / �����������¹�����ˮ�ޡ�
����ֲ����Ҫ����ˮ����ˮ���ķѵ�ʱ�䶼��һ���ġ�
���� ��ǰ���¹���ˮ�ޡ�
ÿ��ֲ�ﶼ������ Alice ���� Bob ����ˮ��
��� Alice �� Bob ����ͬһ��ֲ���ô��ǰˮ����ˮ������˻������ֲ�ｽˮ���������ˮ����ͬ����ô Alice �������ֲ�ｽˮ��
����һ���±�� 0 ��ʼ���������� plants �������� n ��������ɡ�
���У�plants[i] Ϊ�� i ��ֲ����Ҫ��ˮ���������������� capacityA �� capacityB �ֱ��ʾ Alice �� Bob ˮ�޵��������������˽�������ֲ����������¹���ˮ�޵� ���� ��
*/

class Solution {
public:
	int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
		int ans = 0;
		int l = 0, r = plants.size() - 1;
		int A = capacityA, B = capacityB;
		while (l < r) {
			if (A < plants[l]) {
				A = capacityA;
				++ans;
			}
			if (B < plants[r]) {
				B = capacityB;
				++ans;
			}
			A -= plants[l];
			B -= plants[r];
			++l;
			--r;
		}
		if (l == r) {
			if (max(A, B) < plants[l]) {
				++ans;
			}
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}