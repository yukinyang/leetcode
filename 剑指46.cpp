#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
����һ�����֣����ǰ������¹����������Ϊ�ַ�����0 ����� ��a�� ��1 ����� ��b����������11 ����� ��l����������25 ����� ��z����

һ�����ֿ����ж�����롣����ʵ��һ����������������һ�������ж����ֲ�ͬ�ķ��뷽����
*/

class Solution {
public:
	int translateNum(int num) {
		if (num == 0) {
			return 1;
		}
		string s = num2string(num);
		vector<int> dp(s.size() +  1, 0);
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i < s.size() + 1; ++i) {
			string mid;
			//mid = s[i - 2] + s[i - 1];
			mid.push_back(s[i - 2]);
			mid.push_back(s[i - 1]);
			//cout << mid << ' ';
			if (cmp25(mid)) {
				dp[i] = dp[i - 1] + dp[i - 2];
			}
			else{
				dp[i] = dp[i - 1];
			}
			//cout << ' ' << dp[i] << endl;
		}
		return dp[s.size()];
	}

	string num2string(int num) {
		string res = "";
		while (num) {
			char ch = num % 10 + '0';
			res = ch + res;
			num /= 10;
		}
		return res;
	}

	bool cmp25(string a) {
		if (a[0] == '1') {
			return true;
		}
		else if (a[0] == '2') {
			if ((a[1] - '6') < 0) {
				return true;
			}
		}
		return false;
	}
};

int main() {
	Solution s;
	//cout << s.num2string(234) << endl;
	//cout << boolalpha << s.cmp25("26") << endl;
	cout << s.translateNum(12258) << endl;
	system("pause");
	return 0;
}