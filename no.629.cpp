#include <iostream>
#include <vector>

using namespace std;

/*

*/

class Solution {
public:
	int kInversePairs(int n, int k) {
		if (n >= 2 && k > ((n * n - n) / 2)) {
			return 0;
		}
		vector<vector<int>> dp(2, vector<int>(k + 1, 0));
		for (int i = 0; i < n; ++i) {

		}
	}
};

int main() {
	system("pause");
	return 0;
}