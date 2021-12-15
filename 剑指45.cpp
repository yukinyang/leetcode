#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

/*
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
*/

class Solution {
public:
	string minNumber(vector<int>& nums) {
		string res = "";
		vector<string> str_nums;
		for (int num : nums) {
			//str_nums.push_back(num2string(num));
			str_nums.push_back(to_string(num));
		}
		for (int i = 0; i < str_nums.size() - 1; ++i) {
			for (int j = 0; j < str_nums.size() - 1 - i; ++j) {
				string s1 = str_nums[j] + str_nums[j + 1];
				string s2 = str_nums[j + 1] + str_nums[j];
				// cout << s1 << endl;
				// cout << s2 << endl;
				if (str_cmp(s1, s2)) {
					string s = str_nums[j];
					str_nums[j] = str_nums[j + 1];
					str_nums[j + 1] = s;
				}
			}
		}
		for (string s : str_nums) {
			res += s;
		}
		return res;
	}
	string num2string(int num) {
		if (num == 0) {
			return "0";
		}
		string res = "";
		stack<char> mid;
		while (num) {
			int now = num % 10;
			char ch = '0' + now;
			num /= 10;
			mid.push(ch);
		}
		while (!mid.empty()) {
			res += mid.top();
			mid.pop();
		}
		return res;
	}
	bool str_cmp(string a, string b) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] > b[i]) {
				return true;
			}
			else if (a[i] < b[i]) {
				return false;
			}
		}
		return false;
	}
};

int main() {
	Solution s;
	//cout << s.num2string(12) << endl;
	cout << boolalpha << ("5" > "9") << endl;
	system("pause");
	return 0;
}