#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <math.h>
#include <unordered_map>

using namespace std;

/*
�ܼ��� n ������������ɫ�����Ǻ졢�̡����е�һ�֡���Щ���ֲ����� 10 �����Ϊ 0 �� 9 �ĸ��ϡ�

����һ������Ϊ 2n ���ַ��� rings ����ʾ�� n �����ڸ��ϵķֲ���rings ��ÿ�����ַ��γ�һ�� ��ɫλ�ö� ����������ÿ������

�� i ���е� ��һ�� �ַ���ʾ�� i ������ ��ɫ��'R'��'G'��'B'����
�� i ���е� �ڶ��� �ַ���ʾ�� i ������ λ�ã�Ҳ����λ���ĸ����ϣ�'0' �� '9'����
���磬"R3G2B1" ��ʾ������ n == 3 ��������ɫ�Ļ��ڱ��Ϊ 3 �ĸ��ϣ���ɫ�Ļ��ڱ��Ϊ 2 �ĸ��ϣ���ɫ�Ļ��ڱ��Ϊ 1 �ĸ��ϡ�

�ҳ����м��� ȫ��������ɫ ���ĸˣ����������ָ˵�������
*/

class Solution {
public:
	int countPoints(string rings) {
		unordered_map<char, vector<int>> map;
		int n = rings.size();
		int ans = 0;
		for (int i = 0; i < n / 2; ++i) {
			if (map.find(rings[i * 2 + 1]) == map.end()) {
				vector<int> mid(3, 0);
				map[rings[i * 2 + 1]] = mid;
				if (rings[i * 2] == 'B') {
					++map[rings[i * 2 + 1]][0];
				}
				if (rings[i * 2] == 'G') {
					++map[rings[i * 2 + 1]][1];
				}
				if (rings[i * 2] == 'R') {
					++map[rings[i * 2 + 1]][2];
				}
			}
			else {
				if (rings[i * 2] == 'B') {
					++map[rings[i * 2 + 1]][0];
				}
				if (rings[i * 2] == 'G') {
					++map[rings[i * 2 + 1]][1];
				}
				if (rings[i * 2] == 'R') {
					++map[rings[i * 2 + 1]][2];
				}
			}
		}
		unordered_map<char, vector<int>>::iterator it;
		it = map.begin();
		while (it != map.end()) {
			vector<int> col = it->second;
			if (col[0] != 0 && col[1] != 0 && col[2] != 0) {
				++ans;
			}
			++it;
		}
		return ans;
	}
};

int main() {
	system("pause");
	return 0;
}