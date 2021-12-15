#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void Ox2ten(vector<string> input) {
		for (string s : input) {
			cout << to_string(trans(s)) << endl;
		}
	}

	int trans(string s) {
		int ans = 0;
		for (int i = s.size() - 1; i > 1; --i) {
			ans *= 16;
			if (s[i] >= 'A' && s[i] <= 'F') {
				ans += (10 + s[i] - 'A');
			}
			else {
				ans += (s[i] - '0');
			}
		}
		return ans;
	}
};

int main() {
	string input;
	Solution s;
	vector<string> inputs;
	while (cin >> input) {
		inputs.push_back(input);
		s.Ox2ten(inputs);
	}
	//int ans = s.trans("0xAA");
	//cout << ans << endl;
	system("pause");
	return 0;
}