#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
	string decodeCiphertext(string encodedText, int rows) {
		string res;
		int all_len = encodedText.size();
		if (all_len == 0) {
			return res;
		}
		vector<int> bits(rows, 0);
		int length = all_len / rows;
		for (int i = 0; i < rows; ++i) {
			bits[i] = i;
		}
		int nows = 0;
		while (bits[0] != length) {
			if (bits[nows] < length) {
				res.push_back(encodedText[nows * length + bits[nows]]);
			}
			++bits[nows];
			nows = (nows + 1) % rows;
		}
		res = deletetail(res);
		return res;
	}

	string deletetail(string input) {
		while (input[input.size() - 1] == ' ') {
			input.pop_back();
		}
		return input;
	}
};

int main() {
	Solution s;
	string test = "jidoasj1";
	string newtest(test, 4, 4);
	cout << newtest << endl;
	system("pause");
	return 0;
}