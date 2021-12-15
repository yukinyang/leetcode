#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
给定一个偶数长度的数组，其中不同的数字代表着不同种类的糖果，每一个数字代表一个糖果。

你需要把这些糖果平均分给一个弟弟和一个妹妹。返回妹妹可以获得的最大糖果的种类数。
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