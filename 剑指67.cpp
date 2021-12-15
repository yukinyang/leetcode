#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

/*

*/

class Solution {
public:
	int strToInt(string str) {
		bool start = false;
		int isfu = 1;
		string res;
		int real_res = 0;
		for (int i = 0; i < str.size(); i++) {
			if (!start && str[i] == ' ') {
				continue;
			}
			if (str[i] == '-' && start == false) {
				start = true;
				isfu = -1;
				continue;
			}
			if (str[i] - '0' >= 0 && str[i] - '0' < 10 && start == false) {
				start = true;
				res.push_back(str[i]);
				continue;
			}
			if (str[i] - '0' >= 0 && str[i] - '0' < 10 && start == true) {
				res.push_back(str[i]);
				continue;
			}
			if (!(str[i] - '0' >= 0 && str[i] - '0' < 10)) {
				break;
			}
		}
		cout << res << endl;
		for (int i = 0; i < res.size(); i++) {
			real_res *= 10;
			real_res += (res[i] - '0');
			if (real_res > INT_MAX && isfu == 1) {
				return INT_MAX;
			}
			if (real_res > INT_MAX && isfu == -1) {
				return INT_MIN;
			}
		}
		if (isfu == -1) {
			real_res *= -1;
		}
		return real_res;
	}
};

int main() {
	string input = " 012345678";
	Solution s;
	int res = s.strToInt(input);
	system("pause");
	return 0;
}