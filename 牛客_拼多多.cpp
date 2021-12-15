#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int get_diff(int n, string a, string b) {
		vector<int> anum(26, 0);
		vector<int> bnum(26, 0);
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			++anum[a[i] - 'a'];
			++bnum[b[i] - 'a'];
		}
		for (int i = 0; i < 26; ++i) {
			anum[i] -= bnum[i];
		}
		for (int i = 0; i < 26; ++i) {
			ans += anum[i] * i;
		}
		return abs(ans);
	}
};

int main() {
	Solution s;
	int n;
	string a, b;
	cin >> n;
	cin >> a;
	cin >> b;
	int ans = s.get_diff(n, a, b);
	cout << ans;
	system("pause");
	return 0;
}