#include <iostream>
#include <string>

using namespace std;

/*

*/

class Solution {
public:
	bool detectCapitalUse(string word) {
		if (word.size() == 0) {
			return true;
		}
		if (word[0] - 'A' >= 0 && word[0] - 'Z' <= 0) {
			bool res1 = true, res2 = true;
			for (int i = 1; i < word.size(); ++i) {
				if (!(word[i] - 'A' >= 0 && word[i] - 'Z' <= 0)) {
					res1 = false;
					break;
				}
			}
			for (int i = 1; i < word.size(); ++i) {
				if (!(word[i] - 'a' >= 0 && word[i] - 'z' <= 0)) {
					res2 = false;
					break;
				}
			}
			return res1 || res2;
		}
		else {
			for (int i = 0; i < word.size(); ++i) {
				if (!(word[i] - 'a' >= 0 && word[i] - 'z' <= 0)) {
					return false;
				}
			}
			return true;
		}
	}
};

int main() {
	Solution s;
	string test = "Ffff";
	string test1(test, 1);
	cout << boolalpha << s.detectCapitalUse(test) << endl;
	system("pause");
	return 0;
}