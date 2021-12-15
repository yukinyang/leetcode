#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
����һ��ż�����ȵ����飬���в�ͬ�����ִ����Ų�ͬ������ǹ���ÿһ�����ִ���һ���ǹ���

����Ҫ����Щ�ǹ�ƽ���ָ�һ���ܵܺ�һ�����á��������ÿ��Ի�õ�����ǹ�����������
*/

class Solution {
public:
	int distributeCandies(vector<int>& candyType) {
		unordered_map<int, int> type_num;
		for (int i = 0; i < candyType.size(); ++i) {
			if (type_num.find(candyType[i]) != type_num.end()) {
				++type_num[candyType[i]];
			}
			else {
				type_num[candyType[i]] = 1;
			}
		}
		int types = type_num.size();
		if (types > candyType.size() / 2) {
			return candyType.size() / 2;
		}
		else {
			return types;
		}
	}
};

int main() {
	system("pause");
	return 0;
}