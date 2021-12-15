#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>

using namespace std;

/*
����һ���ַ�������ӡ�����ַ������ַ����������С�

�����������˳�򷵻�����ַ������飬�����治�����ظ�Ԫ�ء�
*/

class Solution {
private:
	vector<string> res;
public:
	vector<string> permutation(string s) {
		vector<int> used(s.size(), 0);
		res.clear();
		sort(s.begin(), s.end());
		string now = "";
		get_res(s, now, used);
		return res;
	}

	void get_res(string s, string now, vector<int>& used) {
		if (now.size() == s.size()) {
			res.push_back(now);
			return;
		}
		for (int i = 0; i < s.size(); ++i) {
			if (i > 0 && s[i] == s[i - 1] && used[i - 1] == 1) {
				continue;
			}
			if (used[i] == 0) {
				used[i] = 1;
				now.push_back(s[i]);
				get_res(s, now, used);
				now.pop_back();
				used[i] = 0;
			}
		}
	}
};

int main() {
	Solution s;
	string test = "aab";
	vector<string> strs = s.permutation(test);
	for (string str : strs) {
		cout << str << endl;
	}
	system("pause");
	return 0;
}